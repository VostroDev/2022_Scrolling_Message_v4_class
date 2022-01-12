// Parent: 2022_Scrolling_Message_v4.ino

const char indexpage[] PROGMEM = R"=====(

<!DOCTYPE html><html lang="en">
  <head><meta charset="UTF-8" name="viewport" content="width=device-width, initial-scale=1, user-scalable=no"/>
    <title>Message Board</title>
  
    <style>
      #snackbar {
        visibility: hidden;
        min-width: 280px;
        background-color: #5f5f5f;
        color: #fff;
        text-align: center;
        border-radius: 4px;
        padding-top: 12px;
        padding-bottom: 12px;
        position: fixed;
        z-index: 1;
        bottom: 30px;
        font-size: 17px;
      }
  
      #snackbar.show {
        visibility: visible;
        -webkit-animation: fadein 0.5s, fadeout 0.5s 2.5s;
        animation: fadein 0.5s, fadeout 0.5s 2.5s;
      }
  
      @-webkit-keyframes fadein {
        from {bottom: 0; opacity: 0;} 
        to {bottom: 30px; opacity: 1;}
      }
  
      @keyframes fadein {
        from {bottom: 0; opacity: 0;}
        to {bottom: 30px; opacity: 1;}
      }
  
      @-webkit-keyframes fadeout {
        from {bottom: 30px; opacity: 1;} 
        to {bottom: 0; opacity: 0;}
      }
  
      @keyframes fadeout {
        from {bottom: 30px; opacity: 1;}
        to {bottom: 0; opacity: 0;}
      }

      h3 {
        padding:5px;
      }

      input {
        width:250px;
        padding:5px;
        font-size:1em;
        text-align:left;
      }

      body {
        text-align: center;
        font-family:verdana;
        background-color: #2c3e50;
      }
      
      button {
        border:0;
        border-radius:0.3rem;
        background-color:#1fa3ec;
        color:#fff;
        line-height:2.4rem;
        font-size:1.2rem;
        width:265px;
      }

      ul {
        list-style-type: none;
        margin: 0;
        padding: 0;
        overflow: hidden;
        background-color: #2c3e50;
      }
  
      li {
        float: left;
      }
  
      li a {
        display: block;
        color: white;
        text-align: center;
        padding: 14px 16px;
        text-decoration: none;
      }
  
      li a:hover:not(.active) {
        background-color: #1c2b3a;
      }
  
      .active {
        background-color: #1fa3ec;
      }
        
      #_brigtness {
        font-size: 1.2em;
        text-align: center;
        font-family:verdana;
        padding-bottom: 12px;
        margin: 0;     
      }
      #_message { 
        font-size: 1.2em;
        text-align: center;
        font-family:verdana;
      }

      #brightnessbox {
        display: flex;
        justify-content: center;
        align-items: center;
      }
      
      .range-slider {
        display: inline-block;
        font-family: sans-serif;
        padding: 30px 10px 40px 10px;
        width:265px;
      }

      .range-slider__range {
        -webkit-appearance: none;
        width: calc(100% - (73px));
        height: 10px;
        border-radius: 5px;
        background: #d7dcdf;
        outline: none;
        padding: 0;
        margin: 0;
      }

      .range-slider__range::-webkit-slider-thumb {
        -webkit-appearance: none;
                appearance: none;
        width: 20px;
        height: 20px;
        border-radius: 50%;
        background: #2c3e50; /*2c3e50 */
        cursor: pointer;
        -webkit-transition: background 0.15s ease-in-out;
        transition: background 0.15s ease-in-out;
      }

      .range-slider__range::-webkit-slider-thumb:hover {
        background: #1fa3ec;
      }

      .range-slider__range:active::-webkit-slider-thumb {
        background: #1fa3ec;
      }

      .range-slider__range::-moz-range-thumb {
        width: 20px;
        height: 20px;
        border: 0;
        border-radius: 50%;
        background: #2c3e50;
        cursor: pointer;
        -moz-transition: background 0.15s ease-in-out;
        transition: background 0.15s ease-in-out;
      }

      .range-slider__range::-moz-range-thumb:hover {
        background: #1fa3ec;
      }

      .range-slider__range:active::-moz-range-thumb {
        background: #1fa3ec;
      }

      .range-slider__range:focus::-webkit-slider-thumb {
        box-shadow: 0 0 0 3px #fff, 0 0 0 6px #1fa3ec;
      }

      .range-slider__value {
        display: inline-block;
        position: relative;
        width: 40px;
        color: #fff;
        line-height: 20px;
        text-align: center;
        border-radius: 3px;
        background: #2c3e50;
        padding: 5px 10px;
        margin-left: 8px;
      }

      .range-slider__value:after {
        position: absolute;
        top: 8px;
        left: -7px;
        width: 0;
        height: 0;
        border-top: 7px solid transparent;
        border-right: 7px solid #2c3e50;
        border-bottom: 7px solid transparent;
        content: "";
      }

      ::-moz-range-track {
        background: #d7dcdf;
        border: 0;
      }

      input::-moz-focus-inner,
      input::-moz-focus-outer {
        border: 0;
      }

      #container {
        display:inline-block;
        width:300px;
        border-width: 2px;
        border-color: #333333;
        padding-left:10px;
        padding-right:10px;
        padding-top: 25px;
        padding-bottom:25px;
        border-style: solid;
        border-radius:0.5rem;
        margin-bottom: 45px;
        text-align: center;
        font-family:verdana;
        font-weight: bold;
        background-color: #fff;
        min-height: 373px;
      }

      #signature {
        position:absolute;
        display:flex;
        width: 300px;
        justify-content: center;
        align-items: center;
        text-align: center;
        font-family:verdana;
        font-size: 0.7rem;
        font-weight: bold;
        margin: 0px;
        padding-top: 20px;
        color:#2c3e50;
        opacity: 0.8;
      }
    </style>
  
    <script>
      
    function SendData()
    {
      console.log("save button was clicked!");
    
      var xmessage = document.getElementById("data_form").Message.value;
      var xbrightness = document.getElementById("myRange").value;

      var data = {brightness:xbrightness, message:xmessage};
  
      var xhr = new XMLHttpRequest();
      var url = "/message";
  
      xhr.addEventListener("load", transferComplete);
      xhr.addEventListener("error", transferFailed);
    
      xhr.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // Typical action to be performed when the document is ready:
          if(xhr.responseText != null){
            console.log(xhr.responseText);
            //? alert(xhr.responseText);
          }
        }
      };
    
      xhr.open("POST", url, true);
      xhr.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
      xhr.send(JSON.stringify(data));
      return true;
    }
    
    function transferComplete(evt)
    {
      var mySnack = document.getElementById("snackbar");
      mySnack.textContent  = "Data successfully sent";
        mySnack.className = "show";
        setTimeout(function(){ mySnack.className = mySnack.className.replace("show", ""); }, 3000);
    }
  
    function transferFailed(evt)
    {
      var mySnack = document.getElementById("snackbar");
      mySnack.textContent  = "Oops, something went wrong..";
        mySnack.className = "show";
        setTimeout(function(){ mySnack.className = mySnack.className.replace("show", ""); }, 3000);
    }

    function rangeSlideRW(value) {
        document.getElementById('rangeValueRW').innerHTML = value;
    }
  </script>
  
  </head>
  
  <body >
    <div id="container">
      <div id="msgbox">
        <ul>
          <li><a class="active" href="">Message</a></li>
          <li><a href="/time">Time</a></li>
          <li><a href="/settings">Settings</a></li>
        </ul>
      </div>
      <div>
        <h3 id="_message">Enter Your New Message:</h3>
        <form id="data_form" name="frmText">
          <input maxlength="500" name="Message" type="text" placeholder='New Message'><br/><br/>
        </form>
      </div>

      <div class="range-slider">
        <h3 id="_brigtness">Brightness:</h3>
        <div id="brightnessbox"> 
          <input class="range-slider__range" id="myRange" type="range" value="3" min="1" max="15" oninput="rangeSlideRW(this.value)"  onmousemove="rangeSlideRW(this.value)"></Input>
          <span id="rangeValueRW" class="range-slider__value">3</span>
        </div>
      </div>

      <div>
        <button onclick="SendData()">send data</button>
      </div>

      <div>
        <p id="signature">Designed by: R Wilson 2022</p>
      </div>

      <div style='display:inline-block;min-width:280px;'>
        <div id="snackbar">Display by. Vostro</div>
      </div>
    </div>
  </body>
  
</html>

)=====";
