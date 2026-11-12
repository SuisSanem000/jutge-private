# Pedagogical Constitution & Guidelines

> **Source:** Translated from the original constitution specification in `problem-editor/spec/`  
> **Rule:** This constitution must always be followed strictly with maximum priority.  
> **Navigation:** [Problem Editor Master README](../README.md) • [Problem Spec](./problem-spec.md) • [Claude Skills](../skills/jutge-problems/SKILL.md)

---

## 1. Programming Pedagogy

All educational material must strictly comply with three critical principles:

*   **Efficiency:** A program that executes superfluous instructions or performs unnecessary calculations is completely unacceptable.
    *   *Searches:* If an algorithm does not need to traverse every element of a sequence to produce the result, **it must terminate immediately**. Failing to abort an iteration early when possible is considered a critical error.
*   **Elegance:** Code must be simple, readable, and non-cryptic. Variable names should be intuitive without being excessively verbose. Always minimize the mental effort required to read programs.
*   **Consistency:** All code must adhere to the exact same style throughout the entire documentation.

---

## 2. C++ Language Standard (C++17 Subset)

The dialect used is C++17, but it is restricted to an introductory educational subset:

| Feature | Allowed? | Rule / Restriction |
|---|---|---|
| `auto` | **YES** | Allowed for iterators and clear return types. |
| `enum` / `enum class` | **NO** | Do not use. |
| `typename` in `template` | **YES** | Allowed, but used very infrequently. |
| Range-based `for (... : ...)` | **RESTRICTED** | **Only** allowed on `std::string` and `std::vector` of basic types. |
| UTF-8 string literals | **NO** | Do not use. |
| Lambdas `[](...) { ... }` | **NO** | Do not use. |
| `constexpr` | **NO** | Do not use. |
| `std::string_view` | **NO** | Do not use. |
| `std::unordered_map` / `std::unordered_set` | **NO** | Use standard ordered `std::map` / `std::set`. |
| `std::variant` | **NO** | Do not use. |
| Structured binding / Destructuring | **NO** | Do not use. |
| Exceptions (`try` / `catch` / `throw`) | **NO** | Do not use. |

### Operator Overloading Rule
In container problems (such as `Heap<T>`, `map<K,V>`, or `set<K>`), defining `operator<` to compare elements is permitted when strictly necessary. Aside from `operator<`, **no other operator overloading** should be used.

---

## 3. Educational Concepts & Prerequisites (DAG)

*   **Concept Definition:** A single concept is an idea that can be taught in 10 to 12 minutes using positive and negative examples (e.g. a new data structure, an algorithmic technique, or a specific standard library function).
*   **Prerequisites Graph:** Concepts form a Directed Acyclic Graph (DAG) where directed edges indicate prerequisites. A concept must never be introduced before all of its prerequisites have been taught.
*   **Estimated Durations:**
    *   Reading topic notes: 1 hour.
    *   Lab session: 3 to 6 hours.
    *   Quiz question: ~1 minute.
    *   Short exercise: ~10 minutes.
    *   Full problem: ~1 hour.

---

## 4. Source Code Conventions

*   **File Extensions:** C++ source files must use `.cc`, and header files must use `.hh`.
*   **Function Specifications:** When defining a function for students to implement, provide a clean Doxygen-style header comment with concise `@pre` (preconditions) and `@post` (postconditions).
*   **Code Formatting:** Every source file must be formatted using `clang-format` according to the project's root `.clang-format` configuration.
