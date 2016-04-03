.pragma library

var url ='http://192.168.123.124:8080/qpe/getTagPosition?version=2&humanReadable=true?maxAge=5000';
        //'http://192.168.123.124:8080/qpe/getHAIPLocation?maxAge=5000'

var timerObj;
var xhr = new XMLHttpRequest;

// GET
function get(success, failure) {
    xhr.open("GET", url);
    xhr.onreadystatechange = function() {
        handleResponse(success, failure);
    }
    xhr.send();
}

// POST
function post(arg, success, failure)  {
    //  var xhr = new XMLHttpRequest;
    xhr.open("POST", url);
    xhr.setRequestHeader("Content-Length", arg.length);
    //must have this
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;");
    xhr.onreadystatechange = function() {
        handleResponse(success, failure);
    }
    xhr.send(arg);
}

// 处理返回值
function handleResponse(success, failure){
    if (xhr.readyState === XMLHttpRequest.DONE) {
        if (xhr.status ===  200){
            if (success !== null && success !== undefined)
            {
                var jsonData = xhr.responseText;
                try{
                    success(jsonData, jsonData);
                }catch(e){
                    success(jsonData, {});
                }
            }
        }
        else{
            if (failure !== null && failure !== undefined)
                failure(xhr.responseText, xhr.status);
        }
    }
}




