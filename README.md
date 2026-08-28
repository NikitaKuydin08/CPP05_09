# CPP05_09

> Modules 5–9 of 42's C++ curriculum: exceptions, the four C++ casts, function templates, and template-based containers — the STL stays forbidden until the very end.

![language](https://img.shields.io/badge/language-C%2B%2B98-blue)

---

## Table of Contents

- [Overview](#overview)
- [Module Breakdown](#module-breakdown)
- [Notable Implementations](#notable-implementations)
- [Getting Started](#getting-started)
- [Scale](#scale)
- [Related](#related)

---

## Overview

This picks up right after inheritance and abstract classes: modules 5–8 add proper error handling (nested exception classes instead of exit codes), explicit type conversion, and generic programming. `std::stack` shows up in cpp08 as something to *extend*, not just use — the STL as a base class comes before the STL as a toolbox.

---

## Module Breakdown

| Module | Core topic | Key exercise |
|---|---|---|
| **cpp05** | Exception handling, nested exception classes, the Factory pattern | `Bureaucrat` / `AForm` hierarchy with grade-gated signing; `Intern::makeForm` — a string-driven factory returning the right `AForm` subclass |
| **cpp06** | The four C++ casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`) | `ScalarConverter` — runtime scalar-type detection; `Serializer` — round-tripping a pointer through `uintptr_t`; `Base`/`A`/`B`/`C` — runtime type identification via `dynamic_cast` |
| **cpp07** | Function templates, template specialisation, class templates | `whatever` (templated `swap`/`min`/`max`); `iter` — generic array walker taking a function pointer; `Array<T>` — bounds-checked generic container with a nested `NumOutOfBound` exception |
| **cpp08** | STL containers/iterators, extending vs. wrapping the STL | `easyfind` — generic find over any container; `Span` — capacity-bounded container with `shortestSpan`/`longestSpan`; `MutantStack` — `std::stack` made iterable by inheriting it and exposing the underlying container's iterators |

---

## Notable Implementations

### Exception Hierarchy + Factory — cpp05

`Bureaucrat` holds a `const` grade clamped to `[1, 150]`; going outside that range throws one of two nested exceptions, `GradeTooHighException` or `GradeTooLowException`, both inheriting `std::exception`. Three concrete `AForm` subclasses (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) each define their own required grade to sign vs. execute. `Intern::makeForm` then takes a plain string name and hands back the right concrete form — a small factory that keeps `main` from needing to know the concrete types at all.

### `MutantStack` — cpp08/ex02

`MutantStack<T>` inherits `std::stack<T>` just to get at its protected underlying container (`this->c`) and expose `begin()`/`end()`/`rbegin()`/`rend()` on top of it — `std::stack` normally has no iterators at all. Worth noting: there's a commented-out earlier version in the same file that took a `Container` template parameter and a separate `CompositionStack` built via **composition** instead of inheritance (wrapping a `std::deque` and converting to a `std::stack` on demand) — both approaches were tried before settling on straightforward inheritance.

### `Array<T>` — cpp07/ex02

A generic bounds-checked array with its own nested `NumOutOfBound` exception thrown from `operator[]`. The template's method bodies live in `Array.tpp`, included at the bottom of `Array.hpp` — necessary because template definitions have to be visible wherever the template gets instantiated, not just declared.

### Runtime Type Identification — cpp06/ex02

`identify()` is overloaded for both a `Base*` and a `Base&`. The pointer version uses `dynamic_cast` and checks for `NULL`; the reference version has no null to check against, so it relies on `dynamic_cast` throwing `std::bad_cast` instead — the same underlying mechanism, two different failure conventions depending on whether you're holding a pointer or a reference.

---

## Getting Started

### Requirements

- `g++` with `-std=c++98` support
- GNU Make

### Build & Run

Each exercise has its own `Makefile`:

```sh
cd CPP_05/ex03
make
./intern
```

```sh
cd CPP_08/ex02
make
./mutantstack
```

Standard targets across every exercise:

```sh
make        # build
make clean  # remove object files
make fclean # remove object files and binary
make re     # fclean + rebuild
```

---

## Scale

- **4 modules** (cpp05–cpp08), **~13 exercises**
- **55 source files** (`.cpp` + `.hpp`)
- **~3,300 lines of C++**

*(cpp09 — the full-STL module — isn't done yet and isn't included here.)*

---

## Related

- [CPP00_04](https://github.com/NikitaKuydin08/CPP00_04) — modules 0 through 4: classes, memory ownership, Orthodox Canonical Form, inheritance, and abstract classes. *(link to add)*

---

[↑ Back to top](#cpp05_09)
