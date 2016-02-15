incase you want it

 int main()
{
	struct node *head, *tail, *current =NULL;

	//file read
	while(in.good()){
	in>>data
	insertEnd(data,head,tail); //insert at the end
	}

	//asking user
	writeNode



}
//newNode will be at the tail end, so tail will have to be set
void insertend(int itel, struct node*&head, struct node *&tail)
{
	node * newNode;
	//create node
	newNOde = new node;
	ndeNode-> data = item;
	newNOde -> next = NULL;

	if(!head) P
		newNode->prev=NuLL;
		head = newNode;
	}
	else{
	//something in list
		newNode->prev=tai;l
		tail->next=newNOde;
	}
	tail=newNode; ////make it a new node
}

void adjust(struct node *current, struct node *&head, struct node *&tail)
{
	if(current ->prev != NULL)	//if it is not in the head
		current_>prev->next = current->next; //point he next before this node to one after
	else head=current->next; //make the next one head

	if(current ->next != NULL)	//if it is not in the tail
		current_>next->prev = current->prev; //make the next one point to the previous one
	else tail=current->prev; //change the tail of the node that needs to be displayed

	delete current;
}


void deleteBeg(int delBeg, struct node*&head,  struct node *&tail)
{
	struct node*current=head;

	while(--delBeg >0) //if 0 then we have landed on teh delete node
	{
			current=current->next; // go to node that needs to be deleted
			if(current==NULL) //if delbeg is invalid and we go outisdie we get out
			break;

	}
	if(current!=NULL) //if delbeg is 0 coming into the function or invalid //is it set to some value
		adjust(current,head,tail); //current has node that needs to be deleted

			

}

void deleteEnd(int delBeg, struct node*&head,  struct node *&tail)
{
	struct node*current=tail;

	while(--delBeg >0) //if 0 then we have landed on teh delete node
	{
			current=current->prev; // go to node that needs to be deleted
			if(current==NULL) //if delbeg is invalid and we go outisdie we get out
			break;

	}
	if(current!=NULL) //if delbeg is 0 coming into the function or invalid //is it set to some value
		adjust(current,head,tail); //current has node that needs to be deleted

			

}