#include "Counter.h"

wxIMPLEMENT_APP(counter);

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(5, MainFrame::up)
    EVT_BUTTON(6, MainFrame::down)
    EVT_BUTTON(7, MainFrame::reset)
wxEND_EVENT_TABLE()

Count::Count(){
    num = 1;
}
void Count::up(){
    ++num;
}
void Count::down(){
    --num;
}
void Count::reset(){
    num = 1;
}
int Count::getCount(){
    return num;
}

MainFrame::MainFrame () : wxFrame (nullptr, wxID_ANY, "Counter", wxDefaultPosition, wxSize(400, 400)) {
    #ifdef _WIN32
    this->SetBackgroundColour(*wxBLACK);
    this->SetForegroundColour(*wxWHITE);
    #endif // _WIN32
    count = new Count();
    out = new wxStaticText(this, 1, num, wxPoint(50, 50), wxSize(275, 150));
    #ifdef _WIN32
    out->SetBackgroundColour(*wxBLUE);
    out->SetForegroundColour(*wxBLACK);
    #endif // _WIN32
    out->SetFont(out->GetFont().Scale(7.5));
    up_btn = new wxButton(this, 5, "go up", wxPoint(75, 250), wxSize(100, 25));
    down_btn = new wxButton(this, 6, "go down", wxPoint(225, 250), wxSize(100, 25));
    reset_btn = new wxButton(this, 7, "Reset", wxPoint(150, 300), wxSize(100, 25));
}

void MainFrame::reset(wxCommandEvent &evt){
    count->reset();
    num = "    1";
    out->SetLabel(num);
    evt.Skip();
}
void MainFrame::up(wxCommandEvent &evt){
    count->up();
    if (count->getCount() < 10){
        num = "    " + std::to_string(count->getCount());
    }
    else if (count->getCount() < 100){
        num = "   " + std::to_string(count->getCount());
    }
    else if (count->getCount() < 1000){
        num = "  " + std::to_string(count->getCount());
    }
    else if (count->getCount() < 10000){
        num = " " + std::to_string(count->getCount());
    }
    else {
        num = count->getCount();
    }
    out->SetLabel(num);
    evt.Skip();
}
void MainFrame::down(wxCommandEvent &evt){
    count->down();
    if (count->getCount() < 1){
        count->reset();
        num = "    " + std::to_string(count->getCount());
    }
    else if (count->getCount() <= 10){
        num = "    " + std::to_string(count->getCount());
    }
    else if (count->getCount() <= 100){
        num = "   " + std::to_string(count->getCount());
    }
    else if (count->getCount() <= 1000){
        num = "  " + std::to_string(count->getCount());
    }
    else if (count->getCount() <= 10000){
        num = " " + std::to_string(count->getCount());
    }
    else {
        num = count->getCount();
    }
    out->SetLabel(num);
    evt.Skip();
}

bool counter::OnInit () {
    main = new MainFrame();
    main->Show();

    return true;
}
