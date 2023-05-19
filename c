<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="./shopstyle3.css">
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.5.0/Chart.min.js"></script>

</head>
<body>
    <section class="three">
    <header>
        <div class="left">
            <img src="./images/joke.png" alt="">
            <h1>STAR SHOPPER</h1>
        </div>
        <div class="right">
            <img src="./images/b1.png" alt="">
            <img src="./images/user.png" alt="">
            <a href="./shopindex1.html"><button>Logout</button></a>
        </div>
    </header>
        <section class="product">
            <div class="left">
                <h1>SALES PERFORMANCE</h1>
                <canvas id="salesChart" style="width:100%;max-width:600px; height: 300px;  "></canvas>
                <h1> THIS YEAR GOAL</h1>
              </div>
              <hr>
            <div class="right">
    
                <div class="pro-add">
                    <h4>YOUR PRODUCTS</h4>
                    <button id="bye" class="btn-grp">Add New Product</button>
                </div>
                
                <div class="boxes">
                    <div class="box">
                        <img src="./images/cart1.png" alt="">
                        <h3>Vegetable Box</h3>
                        <p>$129 <span>(10% OFF)</span> </p>
                        <div class="btn">
                            <button class="btn1">Edit</button>
                            <button class="btn2">Delete</button>
                        </div>
                    </div>
                    
                </div>
                
            </div>
    
    </section>
</section>
        <section class="thirteen">
            <div class="header">
                <div class="left">
                    <img src="./images/logo.png">
                    <h1>STAR SELLER</h1>
                </div>
                <div class="right">
                    <img src="./images/user-1.png">
                    <button>Logout</button>
                </div>
            </div>
            <div class="info">
                <div class="left">
                    <input id="title" type="text" placeholder="Product Title" >
                    <input id="des" type="text" placeholder="Product Description" id="big">
                    <div class="flex">
                        <input id="price" type="text" placeholder="Product Price">
                        <input id="discount" type="text" placeholder="Product Discount">
                    </div>
                    <input id="cat" type="text" placeholder="Product Category">
                    <input id="img" type="text" placeholder="Product Image URL">
                    <button id="sri">Add Product</button>
                </div>
                <div class="right">
                    <h1>LIVE PREVIEW</h1>
                    <p>This is how,your customers will see your product on the website</p>
                    <div class="lproduct">
                        <img id="limg" src="./images/vegbox.png">
                    <h2 id="lTitle">Vegetable Box</h2>
                    <div class="price">
                        <!--img src=".images/rupee.png"-->
                        <h3 id="lPrice">129</h3>
                        <li id="lDiscount">(10% OFF )</li>
                    </div>
                    </div>
                    
                    <button>Add to cart</button>
                </div>
            </div>
        </section>

        <section class="where">
        <div class="header">
            <div class="left">
                <img src="./images/logo.png">
                <h1>STAR SELLER</h1>
            </div>
            <div class="right">
                <img src="./images/user-1.png">
                <button>Logout</button>
            </div>
        </div>
        <div class="info">
            <div class="left">
                <input id="ut" type="text" placeholder="Product Title" >
                <input id="ud" type="text" placeholder="Product Description" id="big">
                <div class="flex">
                    <input id="up" type="text" placeholder="Product Price">
                    <input id="udis" type="text" placeholder="Product Discount">
                </div>
                <input id="uc" type="text" placeholder="Product Category">
                <input id="ui" type="text" placeholder="Product Image URL">
                <button id="updatebutton">Update Product</button>
            </div>
            <div class="right">
                <h1>LIVE PREVIEW</h1>
                <p>This is how,your customers will see your product on the website</p>
                <!--img src="./images/vegbox.png">
                <h2>Vegetable Box</h2>
                <div class="price">
                    <img src=".images/rupee.png">
                    <h3>129</h3>
                    <li>(10% OFF )</li>
                </div>
                <button>Add to cart</button-->
                  <div class="updateProduct">
                    <img id="updateImg" src="updateImg" alt="">
                    <h3 id="updateTitle">Product title</h3>
                    <h2 id="updatePrice">200/-</h2>
                    <h6 id="updateDiscount`"></h6>
                   
                </div>  
            </div>
        </div>
    </section>
   
    <script type="module" src="./shopscript3.js"></script>
    
    
</body>
</html>


//graph

new Chart("salesChart", {
    type: "bar",
    data: {
      labels:  ["jan", "feb", "mar", "apr", "may" , "june" , "july" , "aug" , "sep" , "oct" , "nov" , "dec"],
      datasets: [{
        label : 'product 1 ',
        backgroundColor: "pink",
        data:  [28, 55, 68, 41, 81 , 99 , 20 , 30 , 10 , 44 , 56, 139]
      },
      {
        label:'product 2',
        backgroundColor:'cyan',
        data:[32,13,54,70,68,39,21,47,54,19,5,57]
      }
      
    ]
    },
    options: {
      legend: {display: false},
      title: {
        display: true,
        text: "Products Sales per Month "
      }
    }
  });


  //when click on add new products button 
  document.querySelector('#bye').addEventListener('click',()=>{
    document.querySelector('.three').style.display='none';
    document.querySelector('.thirteen').style.display='block'
  })


  import algoliasearch from "algoliasearch";

const client = algoliasearch("YJGIALJJ1Z", "e93fd419ebbb5c49cf5ad08981724dc5");
const index = client.initIndex("pravalika");


document.querySelector('#sri').addEventListener('click',()=>{
  
 
hello()
  
})

  function localStorageToScreen(){
    if(localStorage.getItem('newOne')){
      let newOne=JSON.parse(localStorage.getItem('newOne'))
      newOne.forEach(item=>{
        renderProduct(item, item.uniqueID)
      })
    }

  }
const products=[]
  //adding new product
  function hello(){
   
    let laddu = {
      objectID:Math.floor(Math.random()*1000),
      title: document.querySelector('#title').value,
      description: document.querySelector('#des').value,
      price: document.querySelector('#price').value,
       discount : document.querySelector('#discount').value + '% OFF',
      
      category: document.querySelector('#cat').value,
       
       id:Math.floor(Math.random()*1000) ,
       image : document.querySelector('#img').value,
       
       rating : { count : Math.floor(Math.random()*150) },
       rate:  Math.random()*5,
       
    }
    products.push(laddu)
    index.saveObjects(products).then(hits=>{
      console.log(hits)
      resultProducts(products)
    
   
  })
}

function resultProducts(products){
  products.forEach(laddu => {
      renderProduct(laddu)
      storenewlyAddItems(laddu)
    });
  }


  function storenewlyAddItems(laddu){
    let uniqueID = Math.floor(Math.random()*100)
    let item = {
        title : laddu.title,
        price : laddu.price,
        discount: laddu.discount,
        image:laddu.image
    }
     gowtham(item , uniqueID)
}

let newOne=[];
 function gowtham(item,uniqueID){
  item={...item,uniqueID}
  newOne.push(item)
  localStorage.setItem('newOne',JSON.stringify(newOne))
 }

 function renderProduct(laddu){

let resultdiv = document.createElement('div')
    resultdiv.className = 'box'
    document.querySelector('.boxes').appendChild(resultdiv)

    let resultimage = document.createElement('img')
    resultimage.src = laddu.image
    resultdiv.appendChild(resultimage)

    let productName = document.createElement('h4')
    productName.innerHTML = laddu.title
    resultdiv.appendChild(productName)

    let pricediv = document.createElement('div')
    pricediv.className = 'price'
    resultdiv.appendChild(pricediv)

    let productPrice = document.createElement('h3')
    productPrice.innerHTML = '$'+ laddu.price + '/-'
    pricediv.appendChild(productPrice)

    let productdiscount = document.createElement('p')
    productdiscount.innerHTML = '('+ laddu.discount +')'
    pricediv.appendChild(productdiscount)
    


    let buttonDiv=document.createElement('div')
    buttonDiv.setAttribute('class','btn')
    resultdiv.appendChild(buttonDiv)


    let button1=document.createElement('button')
    button1.setAttribute('class','btn1')
    button1.innerText='Edit'
    buttonDiv.appendChild(button1)
    button1.addEventListener('click',()=>{
      console.log('Delete clicked')
    })

    let button2=document.createElement('button')
    button2.setAttribute('class','btn2')
    button2.innerText='Delete'
    buttonDiv.appendChild(button2)
    button2.addEventListener('click',()=>{
      console.log('Edit clicked')
    })

    // let deleteButton = document.createElement('button')
    // deleteButton.setAttribute('class','delete')
    // deleteButton.innerHTML = 'Delete'
    // resultdiv.appendChild(deleteButton)
    // deleteButton.addEventListener('click',()=>{
    //     console.log('delete clicked')
        // index.deleteObject(m.objectID)
    //})

    // let editbutton = document.createElement('button')
    // editbutton.setAttribute('class','editbutton')
    // editbutton.innerHTML = 'Edit'
    // resultdiv.appendChild(editbutton)
    button2.addEventListener('click',()=>{
        console.log('edit clicked');
        document.querySelector('.three').style.display = 'none'
        document.querySelector('.thirteen').style.display = 'none'
        document.querySelector('.where').style.display = 'block'
        toUpdateNewAddProduct(laddu)
        newAddedProducttoupdatelivePreview(laddu)
    })


   }

   function toUpdateNewAddProduct(laddu){
    document.querySelector('#ut').value = laddu.title
    document.querySelector('#uc').value = laddu.category
    document.querySelector('#ud').value = laddu.description
    document.querySelector('#up').value = laddu.price
    document.querySelector('#udis').value = laddu.discount
    document.querySelector('#ui').value = laddu.image
}
// into live
function newAddedProducttoupdatelivePreview(laddu){
    document.querySelector('#updateTitle').innerHTML = m.title
    document.querySelector('#updatePrice').innerHTML = m.price + '/-'
    document.querySelector('#updateDiscount').innerHTML = '(' + m.discount +')'
    document.querySelector('#updateImage').src = m.image

}
// // the below live section belong's to update product
// live title
document.querySelector('#ut').addEventListener('keyup',()=>{
    let updatelivetitle = document.querySelector('#updateTitle')
    updatelivetitle.innerHTML = document.querySelector('#ut').value
})
// live price 
document.querySelector('#up').addEventListener('keyup',()=>{
    let updateliveprice = document.querySelector('#updatePrice')
    updateliveprice.innerHTML = '$'+document.querySelector('#up').value + '/-'
})
// live discount 
document.querySelector('#udis').addEventListener('keyup',()=>{
    let updatelivediscount = document.querySelector('#updateDiscount')
    updatelivediscount.innerHTML = '$'+document.querySelector('#udis').value + '/-'
})
// live image 
document.querySelector('#ui').addEventListener('keyup',()=>{
    let updateliveimage = document.querySelector('#updateImage')
    updateliveimage.src = document.querySelector('#ui').value 
})
// the below live section belong's to add new product
// live title   
document.querySelector('#ut').addEventListener('keyup',()=>{
    let livetitle = document.querySelector('#lTitle')
    livetitle.innerHTML = document.querySelector('#ut').value
})
// live price
document.querySelector('#up').addEventListener('keyup',()=>{
    let liveprice = document.querySelector('#lPrice')
    liveprice.innerHTML = '$'+ document.querySelector('#up').value + '/-'
})
// live discount
document.querySelector('#udis').addEventListener('keyup',()=>{
    let livediscount = document.querySelector('#lDiscount')
    livediscount.innerHTML = '('+ document.querySelector('#udis').value +'% OFF)'
})
// live image 
document.querySelector('#ui').addEventListener('keyup',()=>{
    let liveimg = document.querySelector('#lImage')
    liveimg.src = document.querySelector('#ui').value
})

localStorageToScreen()

@import url("https://fonts.googleapis.com/css2?family=Sriracha&display=swap");

* {
  margin: 0%;
  padding: 0%;
  font-family: "Times New Roman", Times, serif cursive;
}


.three{
    width: 100vw;
    height: 100vh;
}

header{
    display: grid;
    grid-template-columns: 60% auto;
    height: 13vh;
    width: 100vw;
    background:#f5e28e;
    

}
hr{
    padding: 0;
    margin: 0;
    height: 87vh;
}
header .left{
    display: flex;
    padding: 1rem;
    width: 50%;
    margin-left: 1rem;
}
header .left img{
    height: 8vh;
    pointer-events: none;

}
header .left h1{
    color: black;
    font-size: 1.7rem;
    /* font-weight: 900; */
    padding-left: 0.5rem;
    padding-top: 0.6rem;
    
}
header .right{
    display: flex;
    justify-content: flex-end;
    align-items: center;
    padding: 1rem;
    margin-left: 13.7rem;
    width: 50%;
}
header .right img{
    height: 6vh;
    padding: 1rem;
    pointer-events: none;
    cursor: pointer;
}
header .right button{
    width: 75%;
    height: auto;
    font-size: 1rem;
    font-weight: bold;
    border-radius: 1rem;
    border: none;
   
    background: whitesmoke;
    color: blue;
    padding: 0.6rem 1rem;
    margin: 0.8rem;
    cursor: pointer;
}


.product{
    padding: 0rem 1rem;
    display: flex;
    /* height: 50%; */
}


.left{
    width: 30%;
    margin-top: 0.8rem;
    
}

.product .left img{
    
    margin-top: 2rem;
}


.product .right{
    /*padding: 2rem;*/
    padding: 1rem 1rem;
    width: 70%;
}
.right .boxes .box img{
    height: 20vh;
}

.pro-add{
    display: flex;
    
    justify-content: space-between; 
    margin-bottom: 0.4rem;   
}
 .right .btn .btn1{
    border-radius: 10px;
    border: none;
    background: royalblue;
    color: white;
    width: 50%;
    height: 2rem;
    cursor: pointer;
 
} 

.right .btn .btn2{
    border-radius: 10px;
    border: none;
    background: tomato;
    color: white;
    width: 50%;
    height: 2rem;
    cursor: pointer;
 
} 



.right .btn{
    display: flex;
    gap: 0.3rem;
    margin: 0.5rem 1rem;
}


.product .btn-grp{
    border-radius: 10px;
    border: none;
    background: royalblue;
    color: white;
    width: 15rem;
    height: 2.5rem;
    font-weight: 600;
    cursor: pointer;
 
}

.pro-add h4{
    padding-top: 0.3rem;
    font-size: 1.7rem;
    width: 16rem;
}



.boxes{
    display: flex;
    gap: 2.5rem;
    padding: 0rem 0.5rem;
}

.right h1{
    font-size: 2rem;
    font-weight: bold;
}



.right p{
    color: royalblue;
    font-weight: 600;
    padding: 10px 10px 0px 30px; ;
}
.right p span{
    color: green;
    font-size: 10px;
}
.right .box h3{
    padding-left: 10px;
}
.product .left h1{
    text-align: center;
    font-weight: 1000;
    font-size: 1.5rem;
}
.thirteen{
    display: none;
}
.thirteen .header{
    height: 15vh;
    background: #feea61;
}
.thirteen .header{
    display: flex;
    flex-direction: row;
    align-items: center;
    justify-content: space-between;
}
.thirteen .header .left{
    display: flex;
    align-items: center;
    margin-left: 1rem;
}

.thirteen .header .left h1{
    margin-left: 1rem;
    font-size: 1.5rem;
}
.thirteen .header .left img{
    height: 2rem;
    width: auto;
}
.thirteen .header .right{
    display: flex;
    align-items: center;
    
}
.thirteen .header .right button{
    margin-left: 1rem;
    padding: 0.4rem 1.5rem;
    border-radius: 10px;
    color: #6ea0d8;
    background: white;
    font-size: 1rem;
    border: none;
    outline: none;
    font-family: Roboto;
    font-weight: bold;
}
.thirteen .header .right img{
    height: 2.3rem;
    width: auto;
}

.thirteen .info{
    margin-top: -1rem;
}
.thirteen .info .left{
    background: #e3f2fd;
    padding: 1rem 0rem;
}
.thirteen .info .left input{
    display: flex;
    flex-direction: column;
    margin-left: 2rem;
    margin-top: 1.1rem;
    width: 80%;
    padding: 0.5rem 0rem;
    border: none;
    outline: none;
    border-radius: 5px;
    font-size: 0.8rem;
    font-family: Roboto;
}
.thirteen .info .left #big{
    padding: 1rem 0rem;
}
.thirteen .info .left .flex{
    display: flex;
    width: 84%;
    
}
.thirteen .info .left button{
    margin-left: 2rem;
    margin-top: 1.4rem;
    background: #5271ff;
    color: white;
    outline: none;
    border: none;
    padding: 0.4rem 3rem;
    border-radius: 5px;
    font-family: Roboto;
}
.thirteen .info .right{
    margin-left: 6rem;
}
.thirteen .info .right h1{
    margin-top: 1rem;
}
.thirteen .info .right p{
    margin-top: 1.1rem;
    width: 80%;
    font-family: Roboto;
}
.thirteen .info .right img{
    margin-top: 1.5rem;
}
.thirteen .info .right h2{
    font-size: 1.8rem;
    margin-left: 1.5rem;
    font-family: Roboto;
}
.thirteen .info .right .price{
    display: flex;
    align-items: center;
    margin-top: 1rem;
    margin-left: 2rem;
}
.thirteen .info .right .price img{
    height: auto;
    width: 7%;
    margin-top: 0;
}
.thirteen .info .right .price h3{
    font-size: 1.5rem;
    color: #6dacff;
}
.thirteen .info .right .price li{
    list-style: none;
    margin-left: 0.7rem;
    color: #6dacff;
    font-size: 0.9rem;
}
.thirteen .info .right button{
    margin-left: 1rem;
    margin-top: 1rem;
    background: #5271ff;
    color: white;
    outline: none;
    border: none;
    padding: 0.4rem 2.6rem;
    border-radius: 5px;
    font-family: Roboto;
}



.fourteen .header{
    height: 15vh;
    background: #feea61;
}
.fourteen .header{
    display: flex;
    flex-direction: row;
    align-items: center;
    justify-content: space-between;
}
.fourteen .header .left{
    display: flex;
    align-items: center;
    margin-left: 1rem;
}

.fourteen .header .left h1{
    margin-left: 1rem;
    font-size: 1.5rem;
}
.fourteen .header .left img{
    height: 2rem;
    width: auto;
}
.fourteen .header .right{
    display: flex;
    align-items: center;
    
}
.fourteen .header .right button{
    margin-left: 1.1rem;
    padding: 0.4rem 1.2rem;
    border-radius: 10px;
    color: #6ea0d8;
    background: white;
    font-size: 1rem;
    border: none;
    outline: none;
    font-family: Roboto;
    font-weight: bold;
}
.fourteen .header .right img{
    height: 2.3rem;
    width: auto;
}
.fourteen .info{
    margin-top: -1rem;
}
.fourteen .info .left{
    background: #e3f2fd;
    padding-top: 1rem;
}
.fourteen .info .left input{
    display: flex;
    flex-direction: column;
    margin-left: 2rem;
    margin-top: 1.1rem;
    width: 80%;
    padding: 0.5rem 0rem;
    border: none;
    outline: none;
    border-radius: 5px;
    font-size: 0.8rem;
    font-family: Roboto;
}
.fourteen .info .left #big{
    padding: 1rem 0.3rem;
}
.fourteen .info .left .flex{
    display: flex;
    width: 84%;
    
}
.fourteen .info .left button{
    margin-left: 2rem;
    margin-top: 1.4rem;
    background: #5271ff;
    color: white;
    outline: none;
    border: none;
    padding: 0.4rem 3rem;
    border-radius: 5px;
    font-family: Roboto;
}
.fourteen .info .right{
    margin-left: 6rem;
}
.fourteen .info .right h1{
    margin-top: 1rem;
}
.fourteen .info .right p{
    margin-top: 1.1rem;
    width: 80%;
    font-family: Roboto;
}
.fourteen .info .right img{
    margin-top: 1.5rem;
    margin-left: -1.6rem;
}
.fourteen .info .right h2{
    font-size: 1.8rem;
    margin-left: 1.5rem;
    font-family: Roboto;
}
.fourteen .info .right .price{
    display: flex;
    align-items: center;
    margin-top: 1rem;
    margin-left: 2rem;
}
.fourteen .info .right .price img{
    height: auto;
    width: 7%;
    margin-top: 0;
}
.fourteen .info .right .price h3{
    font-size: 1.5rem;
    color: #6dacff;
}
.fourteen .info .right .price li{
    list-style: none;
    margin-left: 0.7rem;
    color: #6dacff;
    font-size: 0.9rem;
}
.fourteen .info .right button{
    margin-left: 1rem;
    margin-top: 1rem;
    background: #5271ff;
    color: white;
    outline: none;
    border: none;
    padding: 0.4rem 2.6rem;
    border-radius: 5px;
    font-family: Roboto;
}
.fourteen .header .right img{
    height: 2rem;
    width: auto;
}



@media screen and (min-width: 700px){
    .thirteen .info{
        display: flex;
        height: 84vh;
    }
    .thirteen .info .left{
        width: 50%;
        height: 81vh;
        margin-top: 1rem;
    }
    .thirteen .info .left input{
        margin-top: 1.6rem;
        padding: 0.6rem 0rem;
    }
    .thirteen .info .right{
        width: 50%;
    }
    .thirteen .info .left button{
        margin-top: 2.5rem;
        padding: 0.4rem 2.5rem;
    }
    .thirteen .info .left #big{
        padding: 1.3rem 0rem;
    }
    .thirteen .info .right{
        margin-left: 2rem;
    }
    .thirteen .info .right img{
        margin-top: 0.8rem;
        height: 12rem;
        width: auto;
    }.thirteen .info .right button{
        padding: 0.7rem 2rem;
    }
    .fourteen .info{
        display: flex;
        height: 84vh;
        margin-top: 0rem;
    }
    .fourteen .info .left{
        width: 50%;
        height: 81vh;
    }
    .fourteen .info .left input{
        margin-top: 1.6rem;
        padding: 0.6rem 0rem;
    }
    .fourteen .info .right{
        width: 50%;
    }
    .fourteen .info .left button{
        margin-top: 2.5rem;
        padding: 0.4rem 2.5rem;
    }
    .fourteen .info .left #big{
        padding: 1.3rem 0rem;
    }
    .fourteen .info .right{
        margin-left: 2rem;
    }
    .fourteen .info .right img{
        margin-top: 0.8rem;
        height: 12rem;
        width: auto;
    }.fourteen .info .right button{
        padding: 0.7rem 2rem;
    }
}


.where{
    display: none;
}
.where .header{
    height: 15vh;
    background: #feea61;
}
.where .header{
    display: flex;
    flex-direction: row;
    align-items: center;
    justify-content: space-between;
}
.where .header .left{
    display: flex;
    align-items: center;
    margin-left: 1rem;
}

.where .header .left h1{
    margin-left: 1rem;
    font-size: 1.5rem;
}
.where .header .left img{
    height: 2rem;
    width: auto;
}
.where .header .right{
    display: flex;
    align-items: center;
    
}
.where .header .right button{
    margin-left: 1rem;
    padding: 0.4rem 1.5rem;
    border-radius: 10px;
    color: #6ea0d8;
    background: white;
    font-size: 1rem;
    border: none;
    outline: none;
    font-family: Roboto;
    font-weight: bold;
}
.where .header .right img{
    height: 2.3rem;
    width: auto;
}

.where .info{
    margin-top: -1rem;
}
.where .info .left{
    background: #e3f2fd;
    padding: 1rem 0rem;
}
.where .info .left input{
    display: flex;
    flex-direction: column;
    margin-left: 2rem;
    margin-top: 1.1rem;
    width: 80%;
    padding: 0.5rem 0rem;
    border: none;
    outline: none;
    border-radius: 5px;
    font-size: 0.8rem;
    font-family: Roboto;
}
.where .info .left #big{
    padding: 1rem 0rem;
}
.where .info .left .flex{
    display: flex;
    width: 84%;
    
}
.where .info .left button{
    margin-left: 2rem;
    margin-top: 1.4rem;
    background: #5271ff;
    color: white;
    outline: none;
    border: none;
    padding: 0.4rem 3rem;
    border-radius: 5px;
    font-family: Roboto;
}
.where .info .right{
    margin-left: 6rem;
}
.where .info .right h1{
    margin-top: 1rem;
}
.where .info .right p{
    margin-top: 1.1rem;
    width: 80%;
    font-family: Roboto;
}
.where .info .right img{
    margin-top: 1.5rem;
}
.where .info .right h2{
    font-size: 1.8rem;
    margin-left: 1.5rem;
    font-family: Roboto;
}
.where .info .right .price{
    display: flex;
    align-items: center;
    margin-top: 1rem;
    margin-left: 2rem;
}
.where .info .right .price img{
    height: auto;
    width: 7%;
    margin-top: 0;
}
.where .info .right .price h3{
    font-size: 1.5rem;
    color: #6dacff;
}
.where .info .right .price li{
    list-style: none;
    margin-left: 0.7rem;
    color: #6dacff;
    font-size: 0.9rem;
}
.where .info .right button{
    margin-left: 1rem;
    margin-top: 1rem;
    background: #5271ff;
    color: white;
    outline: none;
    border: none;
    padding: 0.4rem 2.6rem;
    border-radius: 5px;
    font-family: Roboto;
}


@media screen and (min-width: 1200px){
    .thirteen .header{
        height: 13vh;
    }
    .thirteen .header .left{
        margin-left: 2rem;
    }
    .thirteen .header .left img{
        height: 2.5rem;
        width: auto;
    }
    .thirteen .header .left h1{
        font-size: 2rem;
    }
    .thirteen.header .right button{
        margin-right: 1rem;
        padding: 0.6rem 1.8rem;
    }
    .thirteen .info{
        height: 87vh;
    }
    .thirteen .info .left{
        height: 86vh;
    }
    .thirteen .info .left input{
        margin-left: 3rem;
        margin-top: 1.9rem;
        padding: 0.85rem;
        border-radius: 10px;
    }
    .thirteen .info .left .flex{
        width: 87%;
    }
    .thirteen .info .left #big{
        padding: 1.7rem 0rem;
    }
    .thirteen .info .left button{
        margin-left: 3rem;
        padding: 0.6rem 3rem;
        margin-top: 2.5rem;
    }
    .thirteen .info .right{
        margin-left: 3rem;
    }
    .thirteen .info .right h1{
        font-size: 1.6rem;
        margin-top: 2rem;
    }
    .thirteen .info .right p{
        width: 40%;
        font-weight: bold;
    }
    .thirteen .info .right img{
        height: 14rem;
        width: auto;
    }
    .thirteen .info .right .price img{
        height: 1.9rem;
        width: auto;
    }
    .thirteen .info .right .price h3{
        font-size: 1.9rem;
    }
    .fourteen .header{
        height: 13vh;
    }
    .fourteen .header .left{
        margin-left: 2rem;
    }
    .fourteen .header .left img{
        height: 2.5rem;
        width: auto;
    }
    .fourteen .header .left h1{
        font-size: 2rem;
    }
    .fourteen .header .right button{
        margin-right: 1rem;
        padding: 0.6rem 1.8rem;
    }
    .fourteen .info{
        height: 87vh;
    }
    .fourteen .info .left{
        height: 86vh;
    }
    .fourteen .info .left input{
        margin-left: 3rem;
        margin-top: 1.9rem;
        padding: 0.85rem;
        border-radius: 10px;
    }
    .fourteen .info .left .flex{
        width: 87%;
    }
    .fourteen .info .left #big{
        padding: 1.7rem 0rem;
    }
    .fourteen .info .left button{
        margin-left: 3rem;
        padding: 0.6rem 3rem;
        margin-top: 2.5rem;
    }
    .fourteen .info .right{
        margin-left: 3rem;
    }
    .fourteen .info .right h1{
        font-size: 1.6rem;
    }
    .fourteen .info .right p{
        width: 40%;
        font-weight: bold;
    }
    .fourteen .info .right img{
        height: 14rem;
        width: auto;
    }
    .fourteen .info .right .price img{
        height: 1.9rem;
        width: auto;
    }
    .fourteen .info .right .price h3{
        font-size: 1.9rem;
    }
}






 
  
