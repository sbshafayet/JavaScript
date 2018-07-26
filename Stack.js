function Stack(){

  const values = [];
  let length = 0;

  this.push = function(value){
    length += 1;
    values.push(value);
  }
  
  this.pop = function(){
    if(length > 0){
      length -= 1;
      return values.pop();
    }else{
      return null;
    }
  }

  this.top = function(){
    return values[length - 1];
  }

  this.getValues = function(){
    return values;
  }
  
}
