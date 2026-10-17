#!/usr/bin/env bash

set -u

cd "$(dirname "$0")/.." || exit 1

PASS=0
FAIL=0

run_test() {
    local description="$1"
    local input="$2"
    local expected="$3"
    local output

    output=$(printf '%s\n' "$input" | timeout 10s ./pipeline 2>&1)
    local status=$?

    if [[ $status -eq 0 ]] && grep -Fq -- "$expected" <<< "$output"; then
        echo "[PASS] $description"
        ((PASS += 1))
    else
        echo "[FAIL] $description"
        echo "Expected to find: $expected"
        echo "Actual output:"
        echo "$output"
        ((FAIL += 1))
    fi
}

echo "======================================"
echo " Multi-Process Pipeline Test Suite"
echo "======================================"

make -s || exit 1

run_test \
    "Basic command execution" \
    'printf "hello\n"' \
    "hello"

run_test \
    "Sorting output" \
    'printf "c\na\nb\n" | sort' \
    "a"

run_test \
    "Word counting" \
    'printf "hello world\n" | wc -w' \
    "2"

run_test \
    "Multiple-process log analysis" \
    'cat data/sample.log | grep ERROR | sort | uniq -c' \
    "ERROR Database connection failed"

run_test \
    "Invalid command handling" \
    'unknowncommand | wc -l' \
    "FAILURE"

echo
echo "======================================"
echo "Passed: $PASS"
echo "Failed: $FAIL"
echo "======================================"

if [[ $FAIL -eq 0 ]]; then
    exit 0
else
    exit 1
fi

