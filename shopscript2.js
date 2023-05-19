document.querySelector('#rgstr_btn').addEventListener('click',()=>{
    

    var name = document.getElementById('name');
    var pw = document.getElementById('pw');
    if(name.value.length == 0){
        alert('Please fill in email');

    }else if(pw.value.length == 0){
        alert('Please fill in password');


    }else{
        localStorage.setItem('name', name.value);
        localStorage.setItem('pw', pw.value);
        alert('Your account has been created');
        window.location='./shopindex1.html';
    }
})