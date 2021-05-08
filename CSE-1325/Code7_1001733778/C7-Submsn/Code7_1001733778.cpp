//Sri Subhash Pathuri

#include<iostream>
#include<stdlib.h>
#include<gtkmm.h>

class MainWindow : public Gtk::Window
{
    public:
        MainWindow();
        void button_OK(Gtk::Entry *entry2);
        void button_Cancel();
};

MainWindow::MainWindow()
{
    //setting title
    set_title("Welcome to My Guessing Game");

    //settign the default size of the box
    set_default_size(800, 400);

    //creating box
    Gtk::Box *MainVBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

    Gtk::MenuBar *MyMenuBar = Gtk::manage(new Gtk::MenuBar());
    MyMenuBar->override_background_color(Gdk::RGBA("dark gray")); //recently added
    MainVBox->pack_start(*MyMenuBar, Gtk::PACK_SHRINK, 0);

    //adding new box to window widet
    add(*MainVBox);

    Gtk::MenuItem *MyFileMenu1= Gtk::manage(new Gtk::MenuItem("_CN",true));
    MyMenuBar->append(*MyFileMenu1);

//SubMenu 1
    Gtk::Menu *MyFileSubMenu1=Gtk::manage(new Gtk::Menu());
    MyFileMenu1->set_submenu(*MyFileSubMenu1);

    Gtk::MenuItem *Sub1_opt11 = Gtk ::manage(new Gtk ::MenuItem("_Cartoon Network",true));
    MyFileSubMenu1->append(*Sub1_opt11);

    Gtk::MenuItem *Sub1_opt12 = Gtk ::manage(new Gtk ::MenuItem("_HBO",true));
    MyFileSubMenu1->append(*Sub1_opt12);

    Gtk::MenuItem *Sub1_opt13 = Gtk ::manage(new Gtk ::MenuItem("_",true));
    MyFileSubMenu1->append(*Sub1_opt13);
    Gtk::MenuItem *MyFileMenu2= Gtk::manage(new Gtk::MenuItem("_Options",true));
    MyMenuBar->append(*MyFileMenu2);
    //SubMenu 2
    Gtk::Menu *MyFileSubMenu2=Gtk::manage(new Gtk::Menu());
    MyFileMenu2->set_submenu(*MyFileSubMenu2);

    Gtk::MenuItem *Sub1_opt21 = Gtk ::manage(new Gtk ::MenuItem("Tom?",true));
    MyFileSubMenu2->append(*Sub1_opt21);

    Gtk::MenuItem *Sub1_opt22 = Gtk ::manage(new Gtk ::MenuItem("there are 3 words and no spaces",true));
    MyFileSubMenu2->append(*Sub1_opt22);

    Gtk::MenuItem *MyFileMenu3= Gtk::manage(new Gtk::MenuItem("Facts",true));
    MyMenuBar->append(*MyFileMenu3);
    //SubMenu 3
    Gtk::Menu *MyFileSubMenu3=Gtk::manage(new Gtk::Menu());
    MyFileMenu3->set_submenu(*MyFileSubMenu3);

    Gtk::MenuItem *Sub1_opt31 = Gtk ::manage(new Gtk ::MenuItem("Most famous Cartoon Network",true));
    MyFileSubMenu3->append(*Sub1_opt31);

    Gtk::MenuItem *Sub1_opt32 = Gtk ::manage(new Gtk ::MenuItem("\n They constantly fight",true));
    MyFileSubMenu3->append(*Sub1_opt32);


    //We are throwing a question to the user

    Gtk::Label *MyLabel = Gtk::manage(new Gtk::Label("\nWhat is your decision ? "));
    MainVBox->pack_start(*MyLabel);
    
     //We are displaying the image to the user
   
    Gtk::Image *MyImage=Gtk::manage(new Gtk::Image{"tom-jerry.png"});
    MainVBox->pack_start(*MyImage);

    //We are declaring the3 boxes for buttons and entry
    Gtk::Box *part2= Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL,0));
    MainVBox->add(*part2);

    Gtk::Box *buttonBox2=Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 1));
    part2->pack_end(*buttonBox2);

    Gtk::Box *buttonBox1=Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 2));
    part2->pack_end(*buttonBox1);

    //Code for Ok Button
    Gtk::Button *ButtonOK=Gtk::manage(new Gtk::Button{"Ok"});
    buttonBox1->pack_start(*ButtonOK);
    ButtonOK->set_border_width(3);

    //Code for CANCEL Button
    Gtk::Button *ButtonCANCEL=Gtk::manage(new Gtk::Button{"Cancel"});
    buttonBox1->pack_start(*ButtonCANCEL);
    ButtonCANCEL->set_border_width(3);

    Gtk::Entry *entryTab = Gtk::manage(new Gtk::Entry());
    entryTab->set_text("Enter your guess here");
    entryTab->select_region(0,entryTab->get_text_length());
    entryTab->signal_activate().connect(sigc::bind<Gtk::Entry *>(sigc::mem_fun(*this,&MainWindow::button_OK),(entryTab)));//recently added
    buttonBox2->add(*entryTab);

    //THis is for the cancel button

    //Alternatively you can connect to m_Combo.signal_Changed().connect

    //programming the signal for the Cancel Button
    ButtonCANCEL->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::button_Cancel));

    //programming the Ok Button Signal
    ButtonOK->signal_clicked().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this, &MainWindow::button_OK),(entryTab)));

    entryTab->add_events(Gdk::FOCUS_CHANGE_MASK);
    //entryTab->signal_activate().connect(sigc::mem_fun(*this,&MainWindow::on_entry_activate));

    //entryTab->signal_focus_out_event().connect(sigc::mem_fun(*this,&MainWindow::on_entry_focus_out_event));
    entryTab->grab_focus();

    MainVBox->show_all();
}

void MainWindow::button_Cancel()
{
    hide();
}

void MainWindow::button_OK(Gtk::Entry *entry2)
{

    std::string sentence=entry2->get_text();
    if(sentence.compare("tomandjerry")==0)
    {
        Gtk::MessageDialog outcome("You guessed <span fgcolor='#0000ff'>correctly.</span>.", true, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_OK, false);
        
        outcome.run();
        hide();
        //Gtk::MessageDialog dlg1("You guessed ")   
    }
    else
    {
        Gtk::MessageDialog result2("You answer is not <span fgcolor='#ff0000'>correct</span>,\nPlease try again", true, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false);
        result2.run();
    }
   //Gtk::MessageDialog HWDialog2{sentence}; 
}

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "");
    MainWindow MyWindow; 
    return app->run(MyWindow);
}
