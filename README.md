# Генератор варіантів (ЛР №6)

Генерує унікальні набори з `n` питань із бази питань розміром `M`, без повторів між варіантами.

## Структура

- `Generator.h` / `Generator.cpp` - клас `Generator`: читання питань, підрахунок кількості сполучень `C(M, n)`, генерація унікальних варіантів.
- `InputSetup.h` / `InputSetup.cpp` - розбір аргументів командного рядка / інтерактивне введення, побудова тестового файлу питань.
- `main.cpp` - точка входу.

## Збірка

**Linux / macOS (g++):**
```bash
g++ -std=c++23 main.cpp Generator.cpp InputSetup.cpp -o zadacha_6_lr_1
```

**Windows (MSVC):**
```bat
cl /std:c++latest /EHsc main.cpp Generator.cpp InputSetup.cpp /Fe:zadacha_6_lr_1.exe
```

**Windows (MinGW g++):**
```bash
g++ -std=c++23 main.cpp Generator.cpp InputSetup.cpp -o zadacha_6_lr_1.exe
```

## Запуск

- `./zadacha_6_lr_1` (Windows: `zadacha_6_lr_1.exe`) - інтерактивно запитує `M` і `n`, генерує `output.txt` та порівнює кількість унікальних варіантів із теоретичним `C(M, n)`.
- `./zadacha_6_lr_1 5 2` - те саме, але `M` і `n` передані аргументами.
- `./zadacha_6_lr_1 questions.txt 2` - використати наявний файл питань і вивести всі унікальні варіанти по `n` питань.

Питання у файлі відокремлюються порожнім рядком.
