function btnClick()
        {

           var login=document.getElementById("login").value;
           var password=document.getElementById("password").value;

            if (login == 'admin'){
                if(password == '123456'){
                    event.preventDefault();
                    document.location.href = '../pages/main.html'


                  //  window.open('../pages/login.html');
                }
                 else{
                alert('Неверный пароль');
                event.preventDefault();// поменял местами вы здесь пароль проверяете а не логин был логин поменял на пароль
                    }
            } else {
                alert('Неверный логин');
                event.preventDefault();

            }
        }