# Отчет по домашнему заданию ЛР6

## Задание

Настроить пакетирование проекта так, чтобы пакет содержал приложение `solver` из предыдущего задания.

## Что сделано

1. В проект добавлены части из задания ЛР3: `formatter`, `solver_lib` и приложение `solver`.
2. В `CMakeLists.txt` добавлена сборка исполняемого файла `solver`.
3. Добавлены install-правила для библиотек и бинарного файла `solver`.
4. Подключен `CPackConfig.cmake`.
5. CI запускает сборку, тесты и создание пакета.

## Проверка локально

```sh
cmake -S . -B _build -DBUILD_TESTS=ON
cmake --build _build
cmake --build _build --target test
cmake --build _build --target package
```

## Проверка CPack

```sh
cd _build
cpack -G TGZ
cpack -G DEB
```

## Ожидаемый результат

В пакете должен находиться исполняемый файл `solver`.

Пример вывода:

```text
CPack: Create package
CPack: - package: ... generated.
```

## Вывод

Домашнее задание исправлено: пакет собирается не просто для библиотеки `print`, а для проекта с приложением `solver`, как указано в задании.

## Ссылка

https://github.com/NorthDakota11/lab6
