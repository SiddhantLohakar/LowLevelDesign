#include<iostream>
#include<vector>
#include<fstream>

using namespace std;


class Element{

   public:
   virtual string render() = 0;
};

class ImgElement : public Element{

   string imgPath;

   public:

   ImgElement(string imgPath){
      this->imgPath = imgPath;
   }

   string render(){
      return this->imgPath;
   }
};

class TextElement : public Element{
      
    string text;

    public:
    TextElement(string text){
      this->text =  text;
    }

    string render(){
       return this->text;
    }
};

class Document{
    
   vector<Element *> elements;

   public:
   void add(Element *element){
      elements.push_back(element);
   }

   string render()
   {
      string result;
      for(auto element: elements){
         result += element->render();
      }

      return result;
   }
   
};

class Persistence{
   public:
   virtual void save(string data){}
};

class SaveToFile : public Persistence{
    
   public:
   void save(string data) override{
      cout<<"Saving to the file";
   }

};


class SaveToDB : public Persistence{
   public:
   void save(string data){
      cout<<"Saving to Database"<<endl;
   }
};



class DocumentEditor{

    private:
    Document *Doc;
    Persistence *Storage;
    string result;

    public:
    DocumentEditor(Document *Doc, Persistence *p){
         this->Doc = Doc;
         this->Storage = p;
    }

    void addImage(string path){
         Doc->add(new ImgElement(path));
    }

    void addText(string text){
         Doc->add(new TextElement(text));
    }

    void save(){
       Storage->save(result);
    }

    string renderDocument(){
         if(result.empty()){
            result = Doc->render();
         }

         return result;
    }
};


int main(){
   
    Document* document = new Document();
    Persistence* persistence = new SaveToFile();

   DocumentEditor* editor = new DocumentEditor(document, persistence);

   editor->addText("Hello World\n");
   editor->addText("How are you\n");
   editor->addImage("Hello.png\n");

   cout<<editor->renderDocument();
   editor->save();

}