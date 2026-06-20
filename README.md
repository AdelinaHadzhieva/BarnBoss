<div class="cover-banner">
    <h1>BARN BOSS </h1>
    <p>Обектно-ориентирана симулационна игра за управление на ферма (C++23)</p>
</div>

<h2>1. Преглед на проекта</h2>
<p><strong>Barn Boss</strong> е конзолно базирано приложение, реализиращо многопотребителска икономическа среда за симулация на ферма. Проектът е разработен съгласно принципите на Обектно-ориентираното програмиране (ООП) и прилага модерни софтуерни архитектурни шаблони за постигане на висока модулност, мащабируемост и лесна поддръжка.</p>

<h2>2. Архитектура и Дизайнерски Шаблони</h2>
<h3>2.1 Command Design Pattern (Шаблон "Команда")</h3>
<p>Цялата потребителска логика е капсулирана в отделни класове, наследяващи интерфейса <code>ICommand</code>. Това напълно изолира основния цикъл в <code>GameSystem</code> от детайлите по изпълнение на командите и позволява лесно добавяне на нови действия без промяна на съществуващия код (Спазване на Open/Closed Principle).</p>

<h3>2.2 Factory Design Pattern (Шаблон "Фабрика")</h3>
<p>Класът <code>CommandFactory</code> е централизираният компонент, отговорен за синтактичния анализ на входния низ от конзолата, проверка на нивата на достъп (Права на Player, MarketManager или TaskManager) и инстанциране на съответния обект-команда.</p>

<h3>2.3 Управление на паметта чрез Модерен C++</h3>
<ul>
    <li><strong>Sober Ownership Model:</strong> Използват се изключително <code>std::unique_ptr</code> в ядрото на <code>GameSystem</code> за безупречно автоматично управление на жизнения цикъл на обектите и предотвратяване на memory leaks.</li>
    <li><strong>Raw Pointer / Reference Observation:</strong> Обектите на командите приемат сурови указатели за полиморфизъм или C++ референции (<code>&amp;</code>) за задължителни ресурси, гарантирайки бързодействие без излишен overhead от <code>shared_ptr</code>.</li>
</ul>

<h2>3. Структура на директориите</h2>
<pre>
├── main.cpp                  # Входна точка на приложението
├── gameSystem.h / .cpp       # Мозъкът на играта, управлява сесиите и жизнения цикъл
├── storage/                  # Управление на инвентар и капацитет
│   ├── barn.h / .cpp         # Хамбар (складиране на продукти)
│   └── farm.h / .cpp         # Ферма (управление на ниви и обори)
├── users/                    # Потребителски роли (Полиморфизъм)
│   ├── user.h / .cpp         # Базов абстрактен клас
│   ├── player.h / .cpp       # Играч (поддържа баланс, скор, хамбар, ферма)
│   ├── marketManager.h / .cpp# Мениджър на пазара
│   └── taskManager.h / .cpp  # Мениджър на задачите
├── boards/                   # Глобални информационни табла
│   ├── taskBoard.h / .cpp    # Списък с активни бизнес задачи
│   └── scoreboard.h / .cpp   # Система за класиране на играчите
└── commands/                 # Архитектура на Command Pattern
    ├── iCommand.h            # Базов интерфейс
    ├── commandFactory.h/.cpp # Фабрика за валидация и парсване на команди
    ├── openMarketCatalogCommand.h / .cpp
    ├── profileInfoCommand.h / .cpp
    ├── showTasksCommand.h / .cpp
    ├── playerCommands/       # Команди, достъпни само за Играчи
    ├── marketManagerCommands/# Команди, достъпни само за Пазарен мениджър
    └── taskManagerCommands/  # Команди, достъпни само за Таск мениджър
</pre>

<h2>4. Игрова Механика и Цикли</h2>
<p>Времето в играта се измерва в индивидуални цикли за всеки <code>Player</code>. Всяка валидна команда за действие (напр. посяване, покупка) напредва играта с <strong>+1 цикъл</strong> за съответния играч, което увеличава прогреса на неговите растения и животни.</p>

<table>
    <thead>
        <tr>
            <th>Команда</th>
            <th>Потребител</th>
            <th>Увеличава цикъла?</th>
            <th>Описание</th>
        </tr>
    </thead>
    <tbody>
        <tr><td><code>register</code> / <code>login</code></td><td>Guest</td><td><span class="badge badge-no">Не</span></td><td>Управление на сесии</td></tr>
        <tr><td><code>profileInfo</code></td><td>Всички</td><td><span class="badge badge-no">Не</span></td><td>Извежда данни за профила</td></tr>
        <tr><td><code>checkBalance</code> / <code>checkBarn</code></td><td>Player</td><td><span class="badge badge-no">Не</span></td><td>Информационни справки</td></tr>
        <tr><td><code>openMarketCatalog</code></td><td>Player/MarketMgr</td><td><span class="badge badge-no">Не</span></td><td>Каталог на пазара</td></tr>
        <tr><td><code>sowPlant</code> / <code>addAnimal</code></td><td>Player</td><td><span class="badge">Да (+1)</span></td><td>Добавяне във фермата</td></tr>
        <tr><td><code>buyItem</code> / <code>sellItem</code></td><td>Player</td><td><span class="badge">Да (+1)</span></td><td>Търговия на пазара</td></tr>
        <tr><td><code>harvest</code></td><td>Player</td><td><span class="badge badge-no">Не</span></td><td>Прибиране на готова продукция</td></tr>
        <tr><td><code>completeTask</code></td><td>Player</td><td><span class="badge">Да (+1)</span></td><td>Изпълнение на задача за награда</td></tr>
        <tr><td><code>restock</code> / <code>changePrice</code></td><td>MarketMgr</td><td><span class="badge badge-no">Не</span></td><td>Администрация на пазара</td></tr>
    </tbody>
</table>

<h2>5. Компилация и Стартиране</h2>
<p>За правилно компилиране на целия проект е необходимо да включите всички директории чрез флаговете за инклудване (<code>-I</code>) и да компилирате рекурсивно всички сорс файлове:</p>

<pre>
g++ -std=c++23 *.cpp storage/*.cpp users/*.cpp boards/*.cpp commands/*.cpp commands/*/*.cpp -o main -I. -I./storage -I./users -I./boards -I./commands -I./commands/marketManagerCommands -I./commands/playerCommands -I./commands/taskManagerCommands
</pre>

<p>Стартирайте изпълнимия файл:</p>
<pre>./main</pre>

<h2>6. Жизнен цикъл на данните (Persistence)</h2>
<ul>
    <li><strong>Зареждане:</strong> При стартиране системата автоматично проверява за наличен файл със запис. Ако съществува – състоянието се възстановява; ако липсва – се генерира нов чист свят с начални пазарни наличности.</li>
    <li><strong>Запис:</strong> При извикване на командата <code>exit</code>, играта сериализира текущите данни за пазара, задачите и всички потребители във файл, след което затваря приложението чисто.</li>
</ul>

</body>
</html>
