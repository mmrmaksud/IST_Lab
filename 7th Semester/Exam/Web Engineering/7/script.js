function validateForm()
{
    let name = document.getElementById("name").value;
    let address = document.getElementById("address").value;
    let email = document.getElementById("email").value;
    let gender = document.getElementById("gender").value;
    let mobile = document.getElementById("mobile").value;
    if(name === "")
    {
        alert("Name is required");
        return false;
    }
    if(address === "")
    {
        alert("Address is required");
        return false;
    }
    let emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if(!emailPattern.test(email))
    {
        alert("Invalid Email Address");
        return false;
    }
    if(gender === "")
    {
        alert("Gender is required");
        return false;
    }
    if(!/^[0-9]{11}$/.test(mobile))
    {
        alert("Mobile Number must be 11 digits");
        return false;
    }
    alert("Form Submitted Successfully");
    return true;
}