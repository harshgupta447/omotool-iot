
#ifndef CODE_H
#define CODE_H

const char htmlContent[] PROGMEM = R"====(
<!DOCTYPE html>
<html>
<head>
  <title>LED Brightness Control</title>

  <meta name="viewport" content="width=device-width, initial-scale=1">

  <style>
    body {
      font-family: Arial, sans-serif;
      background: #101827;
      color: white;
      text-align: center;
      padding: 20px;
    }

    .container {
      max-width: 400px;
      margin: 50px auto;
      padding: 30px 20px;
      background: #1e293b;
      border-radius: 20px;
    }

    h1 {
      color: #38bdf8;
    }

    .brightness-slider {
      width: 100%;
      margin: 30px 0;
      accent-color: #16a34a;
      cursor: pointer;
    }

    #brightnessValue {
      font-size: 35px;
      font-weight: bold;
      color: #4ade80;
    }

    #status {
      font-size: 18px;
      margin-top: 20px;
    }
  </style>
</head>

<body>

  <div class="container">

    <h1>LED Brightness Control</h1>

    <h2>Adjust Brightness</h2>

    <div id="brightnessValue">0%</div>

    <input
      type="range"
      min="0"
      max="100"
      value="0"
      class="brightness-slider"
      id="brightnessSlider"
      oninput="changeBrightness(this.value)"
    >

    <div id="status">LED is OFF</div>

  </div>

  <script>

    let timer;

    function changeBrightness(value) {

      document.getElementById("brightnessValue").innerText =
        value + "%";

      document.getElementById("status").innerText =
        Number(value) > 0 ? "LED is ON" : "LED is OFF";

      clearTimeout(timer);

      timer = setTimeout(() => {

        fetch("/brightness?value=" + value)
          .catch(error => console.log(error));

      }, 50);

    }

  </script>

</body>
</html>
)====";

#endif
