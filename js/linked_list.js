var Node = function(element){
	this.element = element;
	this.next = null;
}


var makelist = function list(){
	this.length = 0;
	this.head = null;
	this.append = append;
	this.indexOf = indexOf;
	this.remove = remove;
	this.insert = insert;
}

function append(element){
		var node = new Node(element);
		var current;
		if (this.head == null) {
			this.head = node;
		}else{
			current = this.head;
			while (current.next){
				current = current.next;
			}
			current.next = node;
		}
			this.length++;
}

function indexOf(element){
	var current = this.head;
	var index = 0;
	while(current){
		if (element === current.element) {
			return index;
		}
		index++;
		current = current.next;
	}
	return index
}

function remove(element){
	var index = this.indexOf(element);
	if (index > -1 && index < this.length) {
		var current = this.head;
		var previous;
		var i = 0;
		if (index == 0) {
			this.head = current.next;
		}else{
			while (i++ < index){
				previous = current;
				current = current.next;
			}
			previous.next = current.next;
		}
		this.length--;
		return current.element;
	}else{
		return null;
	}
}

function insert(position,element){
	if(position >-1 && position < this.length){
		var node = new Node(element);
		var current = this.head;
		var previous;
		var i = 0;
		if (position == 0) {
			node.next = current;
			head = node;
		}else{
			while(i++ < position){
				previous = current;
				current = current.next;
			}
			previous.next = node;
			node.next = current;
		}
		this.length++;
	}else{
		return false;
	}
}

var list = new makelist();
list.append("haha")
list.append("lala")
list.append("wawa")
list.insert(1,"aaaa")
console.log(list.remove("wawa"))
console.log(list)
// console.log(list.indexOf("wawa"))
// console.log(list.head.next)
// console.log(list.length)