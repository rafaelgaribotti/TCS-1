Travis Identifier [![License][license-img]][license-url]
=
Simple Travis example for C using GCC compiler based on the identifier program presented by Delamaro et al. "Introdução ao Teste de Software". Elsevier. 2007.

Tests
-

### Test results:

[<img alt="Build Status" src="https://travis-ci.org/LufeSantos/TCS.svg?branch=warmup" height="40">][travis-url]

**[Code Coverage Report](http://htmlpreview.github.io/?https://github.com/LufeSantos/TCS/blob/warmup/coverage/gcoverage.html)**

### Tests Table
|Test Number| Test Name | Input | Expected Output |
|-|-|-|-|
| 1 | MinSizeAndLetter | "L" | Ok |
| 2 | MaxSize | "letra6" | Ok |
| 3 | MinSizeAndNumber | "2" | Not Ok |
| 4 | Empty | "" | Not Ok |
| 5 | BiggerSize | "letras7" | Not Ok |
| 6 | SpecialChar | "dd~m" | Not Ok |

Authors
------
**Luís Becker**

**Samuel Finatto**

Important files:
----

* [identifier.c](identifier.c)
* [Makefile](Makefile)
* [.travis.yml](.travis.yml)

License
-------
MIT License. See [LICENSE](LICENSE) for details.

[main-url]: https://github.com/LufeSantos/TCS
[readme-url]: https://github.com/LufeSantos/TCS/blob/warmup/README.md
[license-url]: https://github.com/LufeSantos/TCS/blob/warmup/LICENSE
[license-img]: https://img.shields.io/github/license/rsp/travis-hello-modern-cpp.svg
[travis-url]: https://travis-ci.org/github/LufeSantos/TCS
[travis-img]: https://travis-ci.org/LufeSantos/TCS.svg?branch=warmup
[github-follow-url]: https://github.com/LufeSantos/TCS
