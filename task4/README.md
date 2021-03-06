
## Объектно-ориентированое программирование: Задача 3, наследование.

### Постановка задачи

Входные данные:
```
  Дана символьная строка с некоторым выражением, в котором могут содержаться скобки трех видов: {}, [], ().
```

Условия выполнения:
```
- Написать метод проверки правильности расстановки скобок в этой строке.
- Использовать классы стека или очереди для реализации задачи
```

Подробности работы алгоритма:
```
Для подсчета будет использоваться структура данных Стэк.
В стэке будет храниться "тип скобки" в порядке их открытия в строке.

Учитывая условия задачи, необходимо прослеживать правильные закрывания скобок.
Правильным будет только тот случай, когда закрывается ранее открытая скобка (последняя в стэке)
Например, скобки в таком порядке:

(   {   [   (   {   }   )   ]   (   )   }   )
^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^
in  in  in  in  in  out out out in  out out out -- вхождение и выхождение из стэка "типа скобок"

Так как по завершению парсинга строки стэк остался пустым, а также не было замечено процедуры out по отношению к другому типу скобки,
можно заключить, что скобки расставлены верно.
```

Входные данные для проверки:
```
  Любая строка со скобками.
```
