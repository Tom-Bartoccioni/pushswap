# push_swap

> School project (42 / Epitech curriculum) — C

A sorting program that orders a stack of integers using a **restricted set of stack operations**, with the goal of doing so in as few moves as possible.

Only two stacks (`a` and `b`) and a limited instruction set are available: swaps (`sa`, `sb`, `sc`), pushes (`pa`, `pb`), rotates (`ra`, `rb`, `rr`) and reverse rotates (`rra`, `rrb`, `rrr`). The challenge is algorithmic: minimise the number of operations needed to sort the input.

## Tech stack

- **Language:** C
- **Build:** `Makefile`
- Custom utilities included (`get_next_line`, a `printf` implementation)

## Build

```sh
make
./push_swap 2 1 3 6 5 8
```

The output is the sequence of operations that sorts the input; a companion `checker` validates that a sequence actually sorts the stack.

## What I learned

- Designing an efficient sorting strategy under strong operational constraints
- Working with linked lists and stack manipulation in C
- Optimising for move count (chunk / radix-style sorting)
