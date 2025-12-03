# CBMC Verification Example

This directory contains a C program demonstrating automated verification using CBMC (C Bounded Model Checker).

## Overview

The `overflow_check.c` file demonstrates how CBMC can detect integer overflow vulnerabilities. Even when both inputs are constrained to be positive, their sum can overflow and wrap around to a negative value.

## Installation

### macOS
```bash
brew install cbmc
```

## Running the Verification

### Basic verification (checks assertion only)
```bash
cbmc overflow_check.c
```

### With signed overflow checking
```bash
cbmc overflow_check.c --signed-overflow-check
```

### With bounds and overflow checking
```bash
cbmc overflow_check.c --bounds-check --signed-overflow-check
```

## Expected Output

CBMC will find a **counterexample** demonstrating that the assertion `result > 0` can fail. This happens when `x` and `y` are both large positive integers whose sum exceeds `INT_MAX`, causing signed integer overflow.

Example counterexample values:
- x = 1073741824 (2^30)
- y = 1073741824 (2^30)
- result = -2147483648 (overflow wraps to INT_MIN)

## Connection to Automated Verification

This example illustrates key concepts from automated verification:

1. **Symbolic Execution**: CBMC explores all possible values of `x` and `y` symbolically
2. **SAT/SMT Solving**: The verification problem is encoded as a satisfiability problem
3. **Bounded Model Checking**: CBMC unrolls loops and explores paths up to a bound
4. **Counterexample Generation**: When a property violation is found, CBMC provides concrete inputs that trigger the bug

## Relevance to Enterprise Systems

Financial systems like those at U.S. Bank process millions of transactions involving arithmetic operations. Automated verification tools like CBMC can detect overflow vulnerabilities that might cause:
- Incorrect balance calculations
- Transaction processing errors
- Security vulnerabilities

This mirrors how enterprise automation tools systematically check configurations and deployments for potential issues.
