/*id search for the search
names for the to do list */


//test something
// window.addEventListener('load', () => {
    // console.log("items", localStorage.getItem("data"));
// })

window.onload = function(){
    liSaved();
    displayData();
};



//This is to search for items
let search = document.getElementById("search");
let li = document.getElementsByClassName("names");

search.addEventListener("keyup", (e) => {
    const { value } = e.target;

    let searchQuery = value.toLowerCase();

    for(const nameElement of li){
        let name = nameElement.textContent.toLowerCase();
        //store name text and convert to lowercase

        //compare current name to search input
        if(name.includes(searchQuery)){
            //found name matching search, display it
            nameElement.style.display = "block";
        } else{
            //no match, don't display name
            nameElement.style.display = "none";
        }
    }
});

//Edit the items
//might change this to button
//let editItem = document.getElementById("names").getAttribute("value");
//EDit items
/*
let list = document.querySelector("ul");
let editItem = document.querySelector('.names');

editItem.onclick = function(){

list.contentEditable = true;
}
*/
//data id

//Add items
//stops refreshing
const myForm = document.querySelector("#myForm");

myForm.addEventListener('submit', (e) => {
    e.preventDefault();
});

//sorta works :)
//add
function addItem(){

    let text = document.querySelector('#data').value;
    saveData(text);
    //const ul = document.querySelector('ul');
    let inP = document.getElementById("dlt").innerHTML;
    let dlt = document.createElement("button");
    let ed = document.createElement("button");
    let edit = document.getElementById("edt").innerHTML;
    /*let editText = edit.innerHTML;*/
    ed.id = "edt";
    ed.textContent = edit;

    dlt.id = "dlt";
    dlt.textContent = inP;

    //YAYYYYYYYY :)))))))))))
    dlt.onclick = function(){
        dlt.parentElement.remove();
    }
    //YAYYYYY
    
    
    //dlt.addEventListener('click', deleteItem(e));
    //dlt.addEventListener('click', deleteItem);
    let li = document.createElement("li");
    let input = document.getElementById("data").value;
    let t = document.createTextNode(input);


    /*ed.onclick = editItem();*/

    ed.onclick = function(){
        let input = document.createElement("input");
        input.type = "text";
        input.value = "";

        li.append(input);
        input.focus();

        input.addEventListener("blur", () => {
            li.innerHTML = input.value;

            li.appendChild(ed);
            li.append(dlt);

            input.remove();
        });
    }
    /*
    edit.onclick = function(){

        let txt = t.textContent;
        let input = document.createElement("input");
        input.type = "text";
        input.value = txt;
        li.append(input);
        input.focus();

        input.addEventListener("blur", () => {
            li.innerHTML = input.value;
            li.appendChild(edit);
            li.appendChild(dlt);
            input.remove();
        })
    }
    */
    
    //dlt.addEventListener('click', deleteItem(e));
    li.appendChild(t);
    li.appendChild(ed);
    li.appendChild(dlt);
    
    document.getElementById("data").value = "";

    let button = document.createElement("button");
    //let txt = document.createTextNode("\u00D7");
    button.className = "close";
    //button.appendChild(txt);
    //li.appendChild(button);
    let ul = document.querySelector("ul");

    ul.appendChild(li);
    //document.getElementById("dlt").addEventListener('click', deleteItem(e));
}



document.getElementById("b").addEventListener('click', addItem());
//document.getElementById("data").addEventListener('enter', addItem());
//try to make the enter work




//delete li

function deleteItem(e){
    e.parentElement.remove();
}
//works fully :)

document.getElementById("dlt").addEventListener('click', deleteItem(e));



//edit
//sorta works?
//new edit button

/*
document.getElementById("edt").addEventListener('click', function(){
    paragraph.contentEditable = true;
    paragraph.style.backgroundColor = "red";
    console.log("On");
    document.getElementById("edt").addEventListener('click', function(){
        paragraph.contentEditable = false;
        paragraph.style.backgroundColor = "blue";
        console.log("Off");
    })
})
*/






function editItem(e){
    /*let edit = document.getElementById("edt");*/
    let ul = document.querySelector("ul");
    let li = document.querySelector("li");
    let input = document.createElement("input");
    /*const tar = e.target;*/
    //could try some more
    
    input.type = "text";
    input.value = "";
    /*document.body.appendChild(input);*/
    e.append(input);
    input.focus();

    let dlte = document.getElementById("dlt");
    let edit = document.getElementById("edt");

    
    input.addEventListener("blur", () => {
        
        li.innerHTML = input.value;

        li.appendChild(edit);
        li.appendChild(dlte);
        /*ul.appendChild(li);*/
        input.remove();    
    });
    /*ul.appendChild(li);*/

    /*alert("Hey");*/
}

const buttons = document.querySelectorAll("li");
let edBut = document.getElementById('edt');


buttons.forEach(li => {
    li.addEventListener('click', (e) => {
        console.log("Present");
    });
});


//document.getElementById("edt").addEventListener('click', editItem());

//edit button works only for the first li


//storage javascript
//for li
function liSaved(){

    let toStorage = [];

    let store = document.querySelectorAll("li");

    for(let i = 0; i < store.length; i++){
        toStorage.push(store[i].firstChild.textContent);
    }

    const orgArray = JSON.parse(localStorage.getItem('li'));
    const orgItem = addInput = localStorage.getItem("data");
    orgArray.push(orgItem);
    //let addInput = localStorage.getItem("data");
    //let addInput = document.getElementById("data").;
    //toStorage.push(orgItem);

    //JSON.stringify(toStorage, Object.getOwnPropertyNames(toStorage))
    //console.log(toStorage);
    console.log("working"); 
    localStorage.setItem("li", JSON.stringify(orgArray));
    //console.log(localStorage);
}
//not working exactly

//updating the localStorage
let but = document.getElementById('b');
but.addEventListener('click', liSaved());
//for input
function saveData(text){
    const store = text;

    //String(store);
    // console.log("working");
    console.log(store);
    localStorage.setItem("data", store);
    displayData();
}

function displayData(){
    const stores = localStorage.getItem("data");
    // console.log("second working");
    document.getElementById("d").innerHTML = stores;
    console.log(stores);
}

//displayData();




/*
function addItem(){

    
    //we select a container so we can insert our todo items
    
};
*/

//call the function

//we prevent the form subit so we dont get any errors or blank page

//broken

/*
const sButton = document.getElementById("b");

    sButton.onclick('click', (e) => {

        let container = document.querySelector('ul');

        //get value from the input
        let input = document.querySelector("#data").value;

        //create an element for each gotten input value
        const item = document.createElement("li");

        // we set the text(value) of the todo item(li)
        const txt = document.createTextNode(input);

        //we append the text(value) to do created element(li)
        item.appendChild(txt);

        // inser the last result(item with value) inside the container(div)
        document.body.insertAdjacentText(item, container);
    });  
*/