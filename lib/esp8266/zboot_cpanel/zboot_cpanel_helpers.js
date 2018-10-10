<!--
function op(callback) {
  var x = new XMLHttpRequest();
  var u = "op.html";
  var i;
  for(i = 1; i < arguments.length; i++) {
    if(i == 1)
      u += "?";
    else
       u += "&";
    u += arguments[i];
  }
  if(callback)
  {
    x.onreadystatechange = function() {
      if (x.readyState === 4) {
        callback(x.response);
      } 
    }
  }
  x.open("GET", u, true);
  x.send();
}

function getValue(parameterName, valueDefault, callback) {
    var valueResult = valueDefault;
    $.ajax({url: "op.html?"+parameterName, async : false, success: function(result){
      valueResult = result; 
    }});
    return valueResult;
}

function addTag(title) {
   return "<div class=\"w3-tag w3-padding-small w3-border w3-round w3-light-grey w3-right\">" + title + "</div><div class=\"w3-right\">&nbsp;</div>"; 
}

function displayImage(info_string, current_index, coldboot_index, temp_index) {
    var info_array = info_string.split(";");
    var image_name = null;
    var image_version = null;
    var image_location = null;
    var image_date = null;
    var image_index = null;

    for (var item = 0; item < info_array.length; ++item) {
       var tuple = info_array[item].split("=");
       switch(tuple[0])
       {
          case "index": image_index = parseInt(tuple[1]); break;
          case "address": image_location = tuple[1]; break;
          case "version": image_version = tuple[1]; break;
          case "date": image_date = tuple[1]; break;
          case "description": image_name = tuple[1]; break;
          default: break;
       }
    }
          
    if(!image_name)
       return;

    var newDiv = "<div class=\"w3-row w3-padding-large\"><div class=\"w3-card w3-container w3-padding\">";
    if(image_index != null && current_index == image_index)
       newDiv += addTag("Running");
    if(image_index != null && coldboot_index == image_index)
       newDiv += addTag("ColdBoot");
    if(image_index != null && temp_index == image_index)
       newDiv += addTag("Temporary");
    newDiv += "<div class=\"w3-left\" style=\"height:40px\"><b class=\"w3-text-black\">" + image_name + "</b></div><table style=\"font-size:12px\" class=\"w3-table w3-striped w3-border w3-bordered\">";
    if(image_index != null)
    {
       newDiv += "<tr><td>Index</td><td>" + image_index + "</td></tr>";
    }
    if(image_version != null)
    {
       newDiv += "<tr><td>Version</td><td>0x" + parseInt(image_version).toString(16) + "</td></tr>";
    }
    if(image_date != null)
    {
       newDiv += "<tr><td>Build Date</td><td>" + new Date((946684800 + parseInt(image_date)) * 1000) +"</td></tr>";
    }
    if(image_location != null)
    {
       newDiv += "<tr><td>Flash location</td><td>0x" + parseInt(image_location).toString(16) + "</td></tr>";
    }
    newDiv += "</table>";
    if(coldboot_index != image_index)
    {
       newDiv += "<div class=\"w3-left\" style=\"height:45px\"><table cellpadding=\"0\" cellspacing=\"0\" style=\"padding-top:7px\"><tr><td style=\"padding-right:10px\"><button class=\"w3-button w3-black\" onclick=\"op((function() {window.location.reload()})(),'select_boot_index=";
       newDiv += image_index;
       newDiv += "')\">Activate Next Boot</button>";
       newDiv += "</td><td><button class=\"w3-button w3-black\" onclick=\"op((function() {window.location.reload()})(),'invalidate_boot_index=";
       newDiv += image_index;
       newDiv += "')\">Erase Image</button></tr></table></div>";
    }
    newDiv += "</div></div>";
    $('#image_list').append(newDiv)
}

function addStatusItem(name, value)
{
    newItem = "<tr><td>" + name + "</td><td>" + value + "</td></tr>";
    $('#status_table').append(newItem)
}

function updateImageList(count, current_index, coldboot_index, temp_index) {
    for(var index = 0; index < count; ++index)
    {
       var info = getValue("image_info="+index, null);
       if(info != null)
          displayImage(info, current_index, coldboot_index, temp_index);
    }
}
-->
