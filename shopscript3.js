document.querySelector('.six').style.display = 'none'
document.querySelector('.seven').style.display = 'none'
// log out button
document.querySelector('.logoutbuttons').addEventListener('click',()=>{
    window.location = './index.html'
})
// add new product button
document.querySelector('#addnewproductbutton').addEventListener('click',()=>{
    document.querySelector('.five').style.display = 'none'
    document.querySelector('.seven').style.display = 'none'
    document.querySelector('.six').style.display = 'block'
    
})
// this function is to create chart 

new Chart("salesChart", {
  type: "bar",
  data: {
    labels:  ["jan", "mar", "may" , "june"  , "aug"  , "oct"  , "dec"],
    datasets: [{
      label : 'product 1 ',
      backgroundColor: "pink",
      data:  [54,23,17,97,38,67]
    }]
  },
  options: {
    legend: {display: false},
    title: {
      display: true,
      text: "Products Sales per Month "
    }
  }
});

// to add a product by seller to website
import algoliasearch from "algoliasearch"
const client = algoliasearch("RY3RMZSO9V", "0c6f81e725e0645ba2886755ca855f81");
const index = client.initIndex("search");

document.querySelector('#isitworks').addEventListener('click',()=>{
    document.querySelector('.five').style.display = 'block'
    document.querySelector('.seven').style.display = 'none'
    document.querySelector('.six').style.display = 'none'
    console.log('fucking its working');
    // addEventListener('New Product Added For Shopper"s')
    working()
    //  document.querySelector('#newcategory').value = ''

})
// adding newly added products From Local Storage TO Screen
function addingElementsFromLocalStorageTOScreen(){
    if(localStorage.getItem('newly')){
      let  newly = JSON.parse(localStorage.getItem('newly'))
        newly.forEach(item=>{
            renderSingleProduct(item , item.uniqueID)
        })
      }
}
// adding new product function
function working(){
    const products = [];
  
    let m = {
       objectID: Math.floor(Math.random()*100),
       category: document.querySelector('#newcategory').value,
       description: document.querySelector('#newdescription').value ,
       id:Math.floor(Math.random()*1000) ,
       image : document.querySelector('#newimage').value,
       price: document.querySelector('#newprice').value,
       discount : document.querySelector('#newdiscount').value + '% OFF',
       rating : { count : Math.floor(Math.random()*150) },
       rate:  Math.random()*5,
       title: document.querySelector('#newtitle').value
    }
    
     products.push(m)

   index.saveObjects(products).then(hits=>{
       console.log(hits)
       resultProducts(products)
       
   });
}
function resultProducts(products){
    products.forEach(m => {
        renderSingleProduct(m)
        storenewlyAddItems(m)
      });
    }

function storenewlyAddItems(m){
    let uniqueID = Math.floor(Math.random()*100)
    let item = {
        title : m.title,
        price : m.price,
        discount: m.discount,
        image:m.image
    }
     thisIsTimeToStoreProducts(item , uniqueID)
}
//
    let newly = [];

function thisIsTimeToStoreProducts(item , uniqueID){
    item = {...item , uniqueID}
    newly.push(item)
    localStorage.setItem('newly',JSON.stringify(newly))
}
// 
function renderSingleProduct(m){
    let resultdiv = document.createElement('div')
    resultdiv.className = 'products'
    document.querySelector('#newlyaddedproductswillseeninthisdiv').appendChild(resultdiv)

    let resultimage = document.createElement('img')
    resultimage.src = m.image
    resultdiv.appendChild(resultimage)

    let productName = document.createElement('h4')
    productName.innerHTML = m.title
    resultdiv.appendChild(productName)

    let pricediv = document.createElement('div')
    pricediv.className = 'price'
    resultdiv.appendChild(pricediv)

    let productPrice = document.createElement('h2')
    productPrice.innerHTML = '$'+ m.price + '/-'
    pricediv.appendChild(productPrice)

    let productdiscount = document.createElement('h5')
    productdiscount.innerHTML = '('+ m.discount +')'
    pricediv.appendChild(productdiscount)
    
    let deleteButton = document.createElement('button')
    deleteButton.setAttribute('class','delete')
    deleteButton.innerHTML = 'Delete'
    resultdiv.appendChild(deleteButton)
    deleteButton.addEventListener('click',()=>{
        console.log('delete clicked')
        // index.deleteObject(m.objectID)
    })

    let editbutton = document.createElement('button')
    editbutton.setAttribute('class','editbutton')
    editbutton.innerHTML = 'Edit'
    resultdiv.appendChild(editbutton)
    editbutton.addEventListener('click',()=>{
        console.log('edit clicked');
        document.querySelector('.five').style.display = 'none'
        document.querySelector('.six').style.display = 'none'
        document.querySelector('.seven').style.display = 'block'
        toUpdateNewAddProduct(m)
        newAddedProducttoupdatelivePreview(m)
    })


   }
//  to update product newlyadded by seller
function toUpdateNewAddProduct(m){
    document.querySelector('#updatetitle').value = m.title
    document.querySelector('#updatecategory').value = m.category
    document.querySelector('#updatedescription').value = m.description
    document.querySelector('#updateprice').value = m.price
    document.querySelector('#updatediscount').value = m.discount
    document.querySelector('#updateimage').value = m.image
}
// into live
function newAddedProducttoupdatelivePreview(m){
    document.querySelector('#updatelivetitle').innerHTML = m.title
    document.querySelector('#updateliveprice').innerHTML = m.price + '/-'
    document.querySelector('#updatelivediscount').innerHTML = '(' + m.discount +')'
    document.querySelector('#updateliveimage').src = m.image

}
// // the below live section belong's to update product
// live title
document.querySelector('#updatetitle').addEventListener('keyup',()=>{
    let updatelivetitle = document.querySelector('#updatelivetitle')
    updatelivetitle.innerHTML = document.querySelector('#updatetitle').value
})
// live price 
document.querySelector('#updateprice').addEventListener('keyup',()=>{
    let updateliveprice = document.querySelector('#updateliveprice')
    updateliveprice.innerHTML = '$'+document.querySelector('#updateprice').value + '/-'
})
// live discount 
document.querySelector('#updatediscount').addEventListener('keyup',()=>{
    let updatelivediscount = document.querySelector('#updatelivediscount')
    updatelivediscount.innerHTML = '$'+document.querySelector('#updatediscount').value + '/-'
})
// live image 
document.querySelector('#updateimage').addEventListener('keyup',()=>{
    let updateliveimage = document.querySelector('#updateliveimage')
    updateliveimage.src = document.querySelector('#updateimage').value 
})
// the below live section belong's to add new product
// live title   
document.querySelector('#newtitle').addEventListener('keyup',()=>{
    let livetitle = document.querySelector('#livetitle')
    livetitle.innerHTML = document.querySelector('#newtitle').value
})
// live price
document.querySelector('#newprice').addEventListener('keyup',()=>{
    let liveprice = document.querySelector('#liveprice')
    liveprice.innerHTML = '$'+ document.querySelector('#newprice').value + '/-'
})
// live discount
document.querySelector('#newdiscount').addEventListener('keyup',()=>{
    let livediscount = document.querySelector('#livediscount')
    livediscount.innerHTML = '('+ document.querySelector('#newdiscount').value +'% OFF)'
})
// live image 
document.querySelector('#newimage').addEventListener('keyup',()=>{
    let liveimg = document.querySelector('#liveimage')
    liveimg.src = document.querySelector('#newimage').value
})


addingElementsFromLocalStorageTOScreen()

