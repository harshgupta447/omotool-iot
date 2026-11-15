
#ifndef CODE_H
#define CODE_H

const char webpage[] PROGMEM = R"rawliteral(

<!DOCTYPE html>
<html>
<head>
    <title>DHT11 Temperature Monitor</title>

    <meta name="viewport" content="width=device-width, initial-scale=1">

    <style>
        body {
            font-family: Arial, sans-serif;
            background: #eef2f7;
            text-align: center;
            margin: 0;
            padding: 20px;
        }

        h1 {
            color: #1e293b;
        }

        .container {
            max-width: 400px;
            margin: 30px auto;
            background: white;
            padding: 25px;
            border-radius: 15px;
            box-shadow: 0 4px 12px rgba(0,0,0,0.1);
        }

        .card {
            background: #f1f5f9;
            padding: 20px;
            margin: 15px 0;
            border-radius: 12px;
        }

        .value {
            font-size: 40px;
            font-weight: bold;
            color: #2563eb;
        }

        .label {
            font-size: 18px;
            color: #475569;
        }

        #status {
            color: #16a34a;
            font-size: 14px;
        }
    </style>
</head>

<body>

    <h1>DHT11 Monitoring System</h1>

    <div class="container">

        <div class="card">
            <div class="label">Temperature</div>
            <div class="value">
                <span id="temperature">--</span> °C
            </div>
        </div>

        <div class="card">
            <div class="label">Humidity</div>
            <div class="value">
                <span id="humidity">--</span> %
            </div>
        </div>

        <p id="status">Connecting to sensor...</p>

    </div>

    <script>

        function updateData() {

            fetch('/data')
                .then(response => response.json())
                .then(data => {

                    if (data.error) {
                        document.getElementById("status").innerHTML =
                            "Sensor reading failed";
                        return;
                    }

                    document.getElementById("temperature").innerHTML =
                        data.temperature;

                    document.getElementById("humidity").innerHTML =
                        data.humidity;

                    document.getElementById("status").innerHTML =
                        "Sensor connected | Live data";

                })
                .catch(error => {

                    document.getElementById("status").innerHTML =
                        "Connection error";

                });
        }

        updateData();

        setInterval(updateData, 2000);

    </script>

</body>
</html>

)rawliteral";

#endif
