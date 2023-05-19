import algoliasearch from "algoliasearch";

const client = algoliasearch("YJGIALJJ1Z", "e93fd419ebbb5c49cf5ad08981724dc5");
const index = client.initIndex("pravalika");



let data = []


let resultsRootElement = document.querySelector('.boxes');
fetch('https://fakestoreapi.com/products').then(res=>res.json()).then(json=>{
    data = json;
    console.log(data)
})

let products=[]

document.querySelector('#search').addEventListener('keyup', ()=>{
    let searchTerm = document.querySelector('#search').value;
    
    if(String(searchTerm).trim().length>0){
       index.search(searchTerm).then(({hits}) => {
    console.log(hits);
    renderProducts(hits)
  })
     
    
}
    else{
        
        removeElements()
    }

})

// product less than price
document.querySelector('#less').addEventListener('keyup', ()=>{
    let p1Term = document.querySelector('#less').value;
    let resultsArray = []
    if(p1Term.trim().length>0){
        resultsArray=data.filter(product=>(product.price) <= p1Term)
        console.log(resultsArray)
        renderProducts(resultsArray)
    }
    else{
        
        removeElements()
    }

})
//product more than price

document.querySelector('#more').addEventListener('keyup', ()=>{
    let p1Term = document.querySelector('#more').value;
    let resultsArray = []
    if(p1Term.trim().length>0){
        resultsArray=data.filter(product=>(product.price) > p1Term)
        console.log(resultsArray)
        renderProducts(resultsArray)
    }
    else{
        
        removeElements()
    }

})

//category of products
document.querySelector('.b1').addEventListener('click',()=>{
    let vdk=[]
    
    vdk=data.filter(product=>(product.category).includes('men'))
    renderProducts(vdk)

console.log(vdk)
})


document.querySelector('.b2').addEventListener('click',()=>{
    let vk=[]
    
    vk=data.filter(product=>(product.category).includes('women'))
    renderProducts(vk)

console.log(vkk)
})


document.querySelector('.b3').addEventListener('click',()=>{
    let vkd=[]
    
    vkd=data.filter(product=>(product.category).includes('electronics'))
    renderProducts(vkd)

console.log(vkd)
})


document.querySelector('.b4').addEventListener('click',()=>{
    let go=[]
    
    go=data.filter(product=>(product.category).includes('jewelery'))
    renderProducts(go)

console.log(go)
})



   

function renderProducts(products){
    removeElements()
    products.forEach(product=>{
    renderSingleProduct(product);

    })
}


let a=0;

function renderSingleProduct(product){
    let pID=Math.floor(Math.random()*1000)
    let resultDiv = document.createElement('div')
    resultDiv.classList.add('box',pID)
    
    let resultImage = document.createElement('img')
    let resultTitle = document.createElement('h4')
    let resultPrice = document.createElement('p')
    let purchaseButton = document.createElement('button')
    purchaseButton.setAttribute('class','hello')

    resultImage.src = product.image
    resultTitle.innerText = product.title
    resultPrice.innerText ='$'+ product.price
     purchaseButton.innerText = 'Add Cart'
     

resultDiv.appendChild(resultImage)
resultDiv.appendChild(resultTitle)
resultDiv.appendChild(resultPrice)
resultDiv.appendChild(purchaseButton)
resultsRootElement.appendChild(resultDiv)


purchaseButton.addEventListener('click',()=>{
    
    
    purchaseButton.innerText='Added'
    
    
    gowtham(product,pID)
    add(product,pID)
    
   
    
})

}


function gowtham(product,pID){
    
    let p={
        title:product.title,
        price:product.price,

    }
    addingProductsToLocal(p,pID)
}


function addingProductsToLocal(p,pID){
     p={...p,pID}
    products.push(p)
    localStorage.setItem('Products',JSON.stringify(products))
    
}



   

//table page
function add(product){
    
let trname = document.createElement('tr')
    document.querySelector('#cl').appendChild(trname);

    let cartproductname = document.createElement('td')
    cartproductname.style.color = 'black'
    cartproductname.innerHTML = product.title
    trname.appendChild(cartproductname)

    let cartProductQuantity = document.createElement('td')
    cartProductQuantity.style.color = 'black'
    cartProductQuantity.innerHTML = '-'+'1'+'+'
    trname.appendChild(cartProductQuantity)

    let cartProductPrice = document.createElement('td')
    cartProductPrice.style.color = 'black'
    cartProductPrice.style.border = '1px solid black'
    cartProductPrice.innerHTML = product.price
    trname.appendChild(cartProductPrice)

    //console.log(trname);


    document.querySelector('#d').addEventListener('click',()=>{
        document.querySelector('.one').style.display='none'
        document.querySelector('.lastpage').style.display = 'block'
        AddCartProductsImageAndPrice(product)
        
        
    })
    
    
}
document.querySelector('#dude').addEventListener('click',()=>{
    document.querySelector('.set').style.display='none';
    document.querySelector('.one').style.display='block';

})





    function removeElements(){
        document.querySelectorAll('.box').forEach(prod=>{
             prod.remove()

         })

     }

     
    
    function AddCartProductsImageAndPrice(product){
     let lpdiv = document.createElement('div')
     lpdiv.className='pp'
     
     let lpimage = document.createElement('img')
     lpimage.src = product.image

     let lptitle = document.createElement('h3')
     lptitle.innerText = product.title
     
     let lpprice = document.createElement('h4')
     lpprice.innerHTML ='$'+ product.price
     
     lpdiv.appendChild(lpimage)
     lpdiv.appendChild(lptitle)
     lpdiv.appendChild(lpprice)
     
     document.querySelector('#pora').appendChild(lpdiv)


    }
    
    
    
    
    