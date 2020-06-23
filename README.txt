Модуль устанавливается как обычно,
для работы необходимы модули:

Entity API, 
Views Data Export - JSON, 
Views Data Export, 
Views, 
Chaos tools, 
Google Chart Tools Views Integration, 
Google Chart Tools

они указаны в зависимостях.

После установки модуля, можно загрузить вручную курсы за определенный период времени на странице /admin/config/services/custom_currencies
Так же, курсы за последний день загружаются при запуске cron.

Курсы отображаются в табличном виде на странице /currencies-rates, там же можно загрузить данные в json, с учетом включенных фильтров.
В виде диаграммы курсы отображаются нс странице /currencies-rates/chart
