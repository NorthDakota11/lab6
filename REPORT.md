# Отчет по домашнему заданию ЛР6

## Задание

Настроить пакетирование проекта так, чтобы пакет содержал приложение `solver` из предыдущего задания. При создании тега пакет должен собираться автоматически и прикрепляться к GitHub Release.

## Что сделано

1. В проект добавлены части из задания ЛР3: `formatter`, `solver_lib` и приложение `solver`.
2. В `CMakeLists.txt` добавлена сборка исполняемого файла `solver`.
3. Добавлены install-правила для библиотек и бинарного файла `solver`.
4. Подключен `CPackConfig.cmake`.
5. Пакет называется `solver`, а не `print`.
6. Добавлен GitHub Actions workflow `.github/workflows/package.yml`.
7. Workflow запускается по тегам `v*`, собирает пакет и публикует файлы в GitHub Release через `softprops/action-gh-release@v2`.

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

## Публикация релиза

Для публикации пакета нужно создать и отправить тег:

```sh
git tag v0.1.0
git push origin v0.1.0
```

После этого GitHub Actions соберет пакет и прикрепит его к Release.

## Ожидаемый результат

В GitHub Release должны появиться файлы пакета, созданные CPack. В пакете должен находиться исполняемый файл `solver`.

## Вывод

Домашнее задание исправлено: пакет собирается для проекта с приложением `solver` и публикуется в GitHub Release через GitHub Actions.

## Ссылка

https://github.com/NorthDakota11/lab6
