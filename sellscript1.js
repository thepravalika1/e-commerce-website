

document.querySelector('#login_btn').addEventListener('click',()=>{
    var storedName = localStorage.getItem('name');
    var storedPw = localStorage.getItem('pw');

    var userName = document.getElementById('userName');
    var userPw = document.getElementById('userPw');
    // var userRemember = document.getElementById("rememberMe");

    if(userName.value == storedName && userPw.value == storedPw){
        // alert('You are logged in.');
        window.location = './sellindex3.html';

    }else{
        alert('Error on login');
    }
})