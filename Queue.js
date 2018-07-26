function Queue(){

  let length = 0;
  let values = new SinglyLinkedList();

  this.enqueue = function(value){
    values.add(value);
    length += 1;
  }

  this.dequeue = function(value){
    if(length > 0){
      length -= 1;
      return values.removeAt(1);
    }else{
      return null;
    }
  }

  this.getValues = function(){
      return values;
  }

}
