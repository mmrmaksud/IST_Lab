function timeUpdate()
{
    let now = new Date();
    let hour = now.getHours();
    let message;
    if(hour < 12)
    {
        message = "Good Morning! Welcome to Our website.";
    }
    else if(hour < 18)
    {
        message = "Good Afternoon! Welcome to Our website.";
    }
    else
    {
        message = "Good Evening! Welcome to Our website.";
    }
    document.getElementById("greeting").innerText = message;
    // Date Format: dd-mm-yyyy
    let day = String(now.getDate()).padStart(2, '0');
    let month = String(now.getMonth() + 1).padStart(2, '0');
    let year = now.getFullYear();
    // Time Format: hh:mm:ss
    let time = now.toLocaleTimeString();
    document.getElementById("datetime").innerText =
    "Current Date: " + day + "-" + month + "-" + year +
    " | Current Time: " + time;
}
timeUpdate();
setInterval(timeUpdate, 1000);