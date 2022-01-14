// Parent: 2022_Scrolling_Message_v4.ino

const char timepickerpage[] PROGMEM = R"=====(
  
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no">

    <title>Message Board Time</title>

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
          padding-top: 5px;
        }

        input {
          width:250px;
          padding:5px;
          font-size:1em;
        }

        body {
          text-align: center;
          font-family:verdana;
          background-color: #2c3e50;
        }

        button {
          border:0;border-radius:0.3rem;
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

        #cal {
          border-width: 2px;
          border-color: #333333;
          padding-left:10px;
          padding-right:10px;
          padding-top: 15px;
          padding-bottom:15px;
          border-style: solid;
          border-radius:0.5rem;
          margin-bottom: 65px;
          text-align: center;
          font-family:verdana;
          font-weight: bold;
          background-color: #fff;
          box-shadow: 0 0 5px #999999;
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
      </style>
  </head>

  <body>
    <div id="container">
      <div style='display:inline-block;min-width:280px;'>
        <ul>
          <li><a href="/">Message</a></li>
          <li><a class="active" href="/time">Time</a></li>
          <li><a href="/settings">Settings</a></li>
        </ul>
      </div>
      <div>
        <h3>Set Current Time and Date:</h3>
            <form id="data_form" name="frmText">
              <div>
                <input type="datetime-local" id="cal"/>
              </div>
          </form>
        <button onclick="SendTime()">update time</button>
      </div>
      <div style='display:inline-block;min-width:280px;'>
        <div id="snackbar">Display by. R Wilson</div>
      </div>
    </div>

  <script>
    window.addEventListener('load', () => {
        var d = new Date();
        var datestring = d.getFullYear() + "-" + ("0"+(d.getMonth()+1)).slice(-2) + "-" + ("0" + d.getDate()).slice(-2) + 'T' + ("0" + d.getHours()).slice(-2) + ":" + ("0" + d.getMinutes()).slice(-2);
        //console.log(datestring); //"yyyy-MM-ddThh:mm"
        document.getElementById('cal').value = datestring;    
    });

    function hasNumber(myString) {
      return /\d/.test(myString);
    }

    function SendTime()
    {
      console.log("time button was clicked!");
      const fd = new Date(document.getElementById('cal').value);

      if(!hasNumber( fd.getFullYear()) || !hasNumber(fd.getMonth()) || !hasNumber(fd.getDate()) || !hasNumber(fd.getHours()) || !hasNumber(fd.getMinutes()) ){
        console.log("Error: No Time/Date selected")
        var mySnack = document.getElementById("snackbar");
        mySnack.textContent  = "Error: No Time/Date selected";
        mySnack.className = "show";
        setTimeout(function(){ mySnack.className = mySnack.className.replace("show", ""); }, 3000);
        return;
      }

      var senddatestring = ("0" + fd.getDate()).slice(-2) +"."+ ("0"+(fd.getMonth()+1)).slice(-2) +"."+ fd.getFullYear() +" "+ ("0" + fd.getHours()).slice(-2) + ":" + ("0" + fd.getMinutes()).slice(-2);
    
      console.log(senddatestring); 

      var xhr = new XMLHttpRequest();
      var url = "/time/send";

      xhr.addEventListener("load", transferComplete);
      xhr.addEventListener("error", transferFailed);
    
      xhr.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // Typical action to be performed when the document is ready:
          if(xhr.responseText != null){
            console.log(xhr.responseText);
          }
        }
      };
    
      xhr.open("POST", url, true);
      xhr.send(senddatestring);
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
  </script>

  </body>
</html>  


)=====";
