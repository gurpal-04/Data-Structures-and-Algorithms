## Valid Parentheses

Given a string `s` containing just the characters `'(', ')', '{', '}', '[' and ']'`, determine if the input string is valid.

An input string is valid if:

* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct order.
* Every close bracket has a corresponding open bracket of the same type.

### Approach

- made a `char` array *'stack'* of length `l`, where `l` is the length of string `s`.
- integer `top` acts as a top of the stack, initially set to -1. i.e., the stack is empty.

**Note:** We can also make `int` array instead of `char` array, the automatic type conversion will be done.

