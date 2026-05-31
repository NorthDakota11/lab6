# lab06

Лабораторная работа №6 посвящена созданию пакетов с помощью CPack.

Проект основан на библиотеке `print` из предыдущих лабораторных работ. В этой работе добавлена конфигурация CPack и возможность собрать пакет из CMake-проекта.

## Состав проекта

- `CMakeLists.txt` — CMake-сборка, версия проекта и подключение CPack.
- `CPackConfig.cmake` — конфигурация CPack.
- `include/print.hpp` — заголовочный файл библиотеки.
- `sources/print.cpp` — реализация библиотеки.
- `tests/test1.cpp` — простой тест.
- `PackageDescription.txt` — описание пакета.
- `CHANGES.md` — список изменений.
- `LICENSE` — лицензия.
- `.travis.yml` — сборка, тестирование и упаковка в CI.
- `REPORT.md` — отчет по лабораторной работе.

## Сборка и тестирование

```sh
cmake -S . -B _build -DBUILD_TESTS=ON
cmake --build _build
cmake --build _build --target test
```

## Сборка пакета

```sh
cmake --build _build --target package
```

Также можно вызвать CPack напрямую из каталога сборки:

```sh
cd _build
cpack -G TGZ
```

## Версия пакета

Версия пакета: `0.1.0.0`.

## Ссылка на репозиторий

https://github.com/NorthDakota11/lab6
