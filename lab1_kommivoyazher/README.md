# Лабораторная работа №1. Задача коммивояжера

## 1. Что сделано
* **Точный алгоритм (полный перебор):** фиксируем 0-й город как начало и конец маршрута. Для остальных городов перебираем все возможные варианты обхода через функцию `nextPermutation` (всего `(N-1)!` вариантов). Находим самый короткий и самый длинный маршруты, замеряем время работы.
* **Жадный алгоритм (ближайший сосед):** стартуем из города 0, на каждом шаге ищем город с минимальной стоимостью проезда среди непосещенных, в конце возвращаемся в 0.
* **Метрика качества:**
  `Quality = (Max - Greedy) / (Max - Min) * 100%`
  Показывает, насколько жадное решение близко к оптимальному (100% — нашли оптимум, 0% — нашли худший вариант).

---

## 2. Результаты тестов

### Тест 1. Разброс стоимостей от 10 до 100

```text
Dimension: 4x4
  Run #1 | Exact [Min: 175, Max: 300, Time: 8e-07s] | Greedy [Cost: 256, Time: 2e-07s] | Quality: 35.2%
  Run #2 | Exact [Min: 62, Max: 261, Time: 7e-07s] | Greedy [Cost: 62, Time: 2e-07s] | Quality: 100.0%
  Run #3 | Exact [Min: 132, Max: 316, Time: 7e-07s] | Greedy [Cost: 132, Time: 2e-07s] | Quality: 100.0%

Dimension: 6x6
  Run #1 | Exact [Min: 172, Max: 461, Time: 3e-06s] | Greedy [Cost: 246, Time: 2e-07s] | Quality: 74.4%
  Run #2 | Exact [Min: 181, Max: 437, Time: 3e-06s] | Greedy [Cost: 250, Time: 2e-07s] | Quality: 73.0%
  Run #3 | Exact [Min: 126, Max: 397, Time: 4e-06s] | Greedy [Cost: 230, Time: 3e-07s] | Quality: 61.6%

Dimension: 8x8
  Run #1 | Exact [Min: 189, Max: 687, Time: 0.0001s] | Greedy [Cost: 294, Time: 3e-07s] | Quality: 78.9%
  Run #2 | Exact [Min: 248, Max: 666, Time: 0.0001s] | Greedy [Cost: 248, Time: 3e-07s] | Quality: 100.0%
  Run #3 | Exact [Min: 263, Max: 656, Time: 0.0001s] | Greedy [Cost: 384, Time: 3e-07s] | Quality: 69.2%

Dimension: 10x10
  Run #1 | Exact [Min: 218, Max: 862, Time: 0.01s] | Greedy [Cost: 315, Time: 4e-07s] | Quality: 84.9%
  Run #2 | Exact [Min: 289, Max: 885, Time: 0.01s] | Greedy [Cost: 289, Time: 4e-07s] | Quality: 100.0%
  Run #3 | Exact [Min: 241, Max: 842, Time: 0.01s] | Greedy [Cost: 257, Time: 3e-07s] | Quality: 97.3%

Dimension: 11x11
  Run #1 | Exact [Min: 193, Max: 983, Time: 0.1s] | Greedy [Cost: 228, Time: 5e-07s] | Quality: 95.6%
  Run #2 | Exact [Min: 315, Max: 962, Time: 0.1s] | Greedy [Cost: 431, Time: 4e-07s] | Quality: 82.1%
  Run #3 | Exact [Min: 256, Max: 953, Time: 0.1s] | Greedy [Cost: 303, Time: 5e-07s] | Quality: 93.3%

Dimension: 12x12
  Run #1 | Exact [Min: 233, Max: 1058, Time: 1s] | Greedy [Cost: 298, Time: 5e-07s] | Quality: 92.1%
  Run #2 | Exact [Min: 261, Max: 1042, Time: 1s] | Greedy [Cost: 261, Time: 4e-07s] | Quality: 100.0%
  Run #3 | Exact [Min: 250, Max: 1051, Time: 1s] | Greedy [Cost: 289, Time: 6e-07s] | Quality: 95.1%
```

**Средние показатели (10..100):**
* 4x4: Exact ~0.0000007 с, Greedy ~0.0000002 с, Качество 78.4%
* 6x6: Exact ~0.000003 с, Greedy ~0.0000002 с, Качество 69.7%
* 8x8: Exact ~0.0001 с, Greedy ~0.0000003 с, Качество 82.7%
* 10x10: Exact ~0.01 с, Greedy ~0.0000004 с, Качество 94.1%
* 11x11: Exact ~0.10 с, Greedy ~0.0000005 с, Качество 90.3%
* 12x12: Exact ~1.00 с, Greedy ~0.0000005 с, Качество 95.7%

---

### Тест 2. Разброс стоимостей от 10 до 1000

```text
Dimension: 4x4
  Run #1 | Exact [Min: 1833, Max: 2791, Time: 5e-07s] | Greedy [Cost: 2047, Time: 1e-07s] | Quality: 77.7%
  Run #2 | Exact [Min: 1569, Max: 3375, Time: 4e-07s] | Greedy [Cost: 1569, Time: 2e-07s] | Quality: 100.0%
  Run #3 | Exact [Min: 1326, Max: 2315, Time: 5e-07s] | Greedy [Cost: 1571, Time: 1e-07s] | Quality: 75.2%

Dimension: 6x6
  Run #1 | Exact [Min: 1117, Max: 4433, Time: 3e-06s] | Greedy [Cost: 1117, Time: 2e-07s] | Quality: 100.0%
  Run #2 | Exact [Min: 1327, Max: 4265, Time: 4e-06s] | Greedy [Cost: 2387, Time: 2e-07s] | Quality: 63.9%
  Run #3 | Exact [Min: 1866, Max: 4668, Time: 3e-06s] | Greedy [Cost: 2366, Time: 2e-07s] | Quality: 82.2%

Dimension: 8x8
  Run #1 | Exact [Min: 1956, Max: 6876, Time: 0.0001s] | Greedy [Cost: 2874, Time: 3e-07s] | Quality: 81.3%
  Run #2 | Exact [Min: 903, Max: 6005, Time: 0.0001s] | Greedy [Cost: 1591, Time: 3e-07s] | Quality: 86.5%
  Run #3 | Exact [Min: 1700, Max: 6225, Time: 0.0001s] | Greedy [Cost: 1700, Time: 3e-07s] | Quality: 100.0%

Dimension: 10x10
  Run #1 | Exact [Min: 2432, Max: 8337, Time: 0.01s] | Greedy [Cost: 3442, Time: 4e-07s] | Quality: 82.9%
  Run #2 | Exact [Min: 1993, Max: 8064, Time: 0.01s] | Greedy [Cost: 2618, Time: 5e-07s] | Quality: 89.7%
  Run #3 | Exact [Min: 1289, Max: 8844, Time: 0.01s] | Greedy [Cost: 2323, Time: 4e-07s] | Quality: 86.3%

Dimension: 11x11
  Run #1 | Exact [Min: 933, Max: 9147, Time: 0.1s] | Greedy [Cost: 1751, Time: 4e-07s] | Quality: 90.0%
  Run #2 | Exact [Min: 1969, Max: 9354, Time: 0.1s] | Greedy [Cost: 3028, Time: 5e-07s] | Quality: 85.7%
  Run #3 | Exact [Min: 2248, Max: 9662, Time: 0.1s] | Greedy [Cost: 2888, Time: 6e-07s] | Quality: 91.4%

Dimension: 12x12
  Run #1 | Exact [Min: 1461, Max: 10242, Time: 1s] | Greedy [Cost: 2302, Time: 7e-07s] | Quality: 90.4%
  Run #2 | Exact [Min: 1874, Max: 10527, Time: 1s] | Greedy [Cost: 3020, Time: 5e-07s] | Quality: 86.8%
  Run #3 | Exact [Min: 1279, Max: 9955, Time: 1s] | Greedy [Cost: 2456, Time: 5e-07s] | Quality: 86.4%
```

**Средние показатели (10..1000):**
* 4x4: Exact ~0.0000005 с, Greedy ~0.0000001 с, Качество 84.3%
* 6x6: Exact ~0.000003 с, Greedy ~0.0000002 с, Качество 82.0%
* 8x8: Exact ~0.0001 с, Greedy ~0.0000003 с, Качество 89.3%
* 10x10: Exact ~0.01 с, Greedy ~0.0000004 с, Качество 86.3%
* 11x11: Exact ~0.10 с, Greedy ~0.0000005 с, Качество 89.0%
* 12x12: Exact ~1.00 с, Greedy ~0.0000006 с, Качество 87.9%

---

## 3. Выводы по заданию

1. **Когда перебор перестает работать:**
   До 10 городов перебор работает незаметно (сотые доли секунды). При 12 городах перебор 40 млн вариантов уже занимает 1 секунду. При 13 городах будет около 12 секунд, при 14 — около 3 минут, а при 15 — больше получаса. То есть начиная с **13–14 городов** решать задачу полным перебором на практике уже нереально.
2. **Как работает жадный алгоритм:**
   Отрабатывает моментально на любых протестированных матрицах (меньше микросекунды). Среднее качество держится в районе **85–90%**, в некоторых тестах совпадает с точным минимумом (100%).
3. **Почему качество иногда сильно падает (до 35–63%):**
   Жадный алгоритм не смотрит на общую картину, а просто выбирает самый дешевый шаг прямо сейчас. Из-за этого к концу маршрута он часто оставляет дорогие ребра, по которым вынужден возвращаться на старт. На маленьких графах (4x4, 6x6) одно такое дорогое ребро сразу портит весь процент качества.
4. **Влияние разброса цен:**
   Увеличение диапазона цен (с 10..100 до 10..1000) никак не ухудшило точность: среднее качество в обоих экспериментах осталось на уровне 85–87%.