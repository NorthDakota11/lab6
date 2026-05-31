# Отчет по лабораторной работе №6

## Тема

Пакетирование CMake-проекта с помощью CPack.

## Цель работы

Добавить в CMake-проект конфигурацию CPack и научиться собирать пакет из исходного проекта.

## Выполненные действия

1. Добавлены переменные версии проекта: `0.1.0.0`.
2. Добавлен файл `CPackConfig.cmake`.
3. В `CMakeLists.txt` подключен файл `CPackConfig.cmake`.
4. Добавлены install-правила для библиотеки и заголовочных файлов.
5. Добавлены файлы описания пакета и списка изменений.
6. Travis CI настроен на сборку, тестирование и создание пакета.

## Команды сборки

```sh
cmake -S . -B _build -DBUILD_TESTS=ON
cmake --build _build
cmake --build _build --target test
```

## Команды создания пакета

```sh
cmake --build _build --target package
```

Или напрямую через CPack:

```sh
cd _build
cpack -G TGZ
```

## Ожидаемый вывод CPack

При успешной упаковке CPack создает архив с проектом.

Пример результата:

```text
CPack: Create package using TGZ
CPack: Install projects
CPack: Create package
CPack: - package: .../print-0.1.0.0-Linux.tar.gz generated.
```

## Результат

В результате выполнения лабораторной работы проект можно собрать, протестировать и упаковать с помощью CPack.

## Ссылка на репозиторий

https://github.com/NorthDakota11/lab6
