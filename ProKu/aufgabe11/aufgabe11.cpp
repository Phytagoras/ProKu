#include <deque>

#include "canvas_window.hpp"
#include "shape.hpp"

// TODO: Fuell mich mit Leben!

class Rectangle : public Proku::Shape {
   private:
    int x, y;
    int breite, hoehe;

   public:
    Rectangle() {
        x = 0;
        y = 0;
        breite = 50;
        hoehe = 50;
    }
    Rectangle(int pX, int pY) {
        x = pX;
        y = pY;
        breite = 50;
        hoehe = 50;
    }
    Rectangle(int pX, int pY, int pBrei, int oHoe) {
        x = pX;
        y = pY;
        breite = pBrei;
        hoehe = oHoe;
    }
    void draw(Proku::Canvas& canvas) const override {
        canvas.draw_rect(x, y, breite, hoehe);
    }
    bool hit_test(int px, int py) const override {
        return (px > x && px < x + breite && py > y && py < y + hoehe);
    }
    void move_by(int dx, int dy) override {
        x = x + dx;
        y = y + dy;
    }
};
class Circle : public Proku::Shape {
   private:
    int x, y;
    int radius;

   public:
    Circle() {
        x = 0;
        y = 0;
        radius = 25;
    }
    Circle(int pX, int pY) {
        x = pX;
        y = pY;
        radius = 25;
    }
    Circle(int pX, int pY, int pR) {
        x = pX;
        y = pY;
        radius = pR;
    }
    void draw(Proku::Canvas& canvas) const override {
        canvas.draw_circle(x, y, radius);
    }
    bool hit_test(int px, int py) const override {
        return (((px - x) * (px - x) + (py - y) * (py - y)) < radius * radius);
    }
    void move_by(int dx, int dy) override {
        x = x + dx;
        y = y + dy;
    }
};

class ShapeWindow : public Proku::CanvasWindow {
   public:
    /// Konstruktor
    ShapeWindow() : Proku::CanvasWindow("ShapeWindow", 640, 480) {
        isMousePressed = false;
        mousePositionX = 0;
        mousePositionY = 0;
        selected = -1;
        shapes.push_back(new Rectangle());
        shapes.push_back(new Circle());
        shapes.push_back(new Rectangle(100, 100));
        shapes.push_back(new Circle(200, 200));
    }

   protected:
    // Ueberschreibe die on_paint() Methode von Window
    virtual void on_paint() override {
        // Wir nutzen hier die Methoden der Basisklasse zum Zeichnen

        // Beginne Zeichnung
        this->paint_begin();
        int index = 0;
        for (auto it = shapes.begin(); it != shapes.end(); it++) {
            if (index == selected)
                this->select_color(1, 0, 0);
            else
                this->select_color(0, 0, 0);
            (*it)->draw(*this);
            index++;
        }

        // Beende Zeichnung
        this->paint_finish();
    }
    virtual void on_mouse_button(int x, int y, int button,
                                 bool pressed) override {
        if (pressed) {
            isMousePressed = true;
            int index = 0;
            selected = -1;
            for (auto it = shapes.begin(); it != shapes.end(); it++) {
                if ((*it)->hit_test(x, y)) selected = index;
                index++;
            }
            this->redraw();
        } else
            isMousePressed = false;
    }
    virtual void on_mouse_motion(int x, int y) override {
        if (isMousePressed) {
            int index = 0;
            for (auto it = shapes.begin(); it != shapes.end(); it++) {
                if (index == selected) {
                    (*it)->move_by(x - mousePositionX, y - mousePositionY);
                    this->redraw();
                    break;
                }
                index++;
            }
        }
        mousePositionX = x;
        mousePositionY = y;
    }
    virtual void on_key_press(int keycode) override {
        switch (keycode) {
            case 10:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                shapes.push_back(
                    new Rectangle(mousePositionX, mousePositionY, 15, 10));
                selected = int(shapes.size()) - 1;
                this->redraw();
                break;
            case 11:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                shapes.push_back(
                    new Rectangle(mousePositionX, mousePositionY, 40, 20));
                selected = int(shapes.size()) - 1;
                this->redraw();
                break;
            case 12:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                shapes.push_back(
                    new Rectangle(mousePositionX, mousePositionY, 90, 30));
                selected = int(shapes.size()) - 1;
                this->redraw();
                break;
            case 13:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                shapes.push_back(
                    new Circle(mousePositionX, mousePositionY, 15));
                selected = int(shapes.size()) - 1;
                this->redraw();
                break;
            case 14:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                shapes.push_back(
                    new Circle(mousePositionX, mousePositionY, 35));
                selected = int(shapes.size()) - 1;
                this->redraw();
                break;
            case 15:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                shapes.push_back(
                    new Circle(mousePositionX, mousePositionY, 95));
                selected = int(shapes.size()) - 1;
                this->redraw();
                break;
            case 111:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                if (selected != -1) {
                    int index = 0;
                    for (auto it = shapes.begin(); it != shapes.end(); it++) {
                        if (index == selected) {
                            (*it)->move_by(0, -10);
                            this->redraw();
                            break;
                        }
                        index++;
                    }
                }
                break;
            case 113:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                if (selected != -1) {
                    int index = 0;
                    for (auto it = shapes.begin(); it != shapes.end(); it++) {
                        if (index == selected) {
                            (*it)->move_by(-10, 0);
                            this->redraw();
                            break;
                        }
                        index++;
                    }
                }
                break;
            case 114:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                if (selected != -1) {
                    int index = 0;
                    for (auto it = shapes.begin(); it != shapes.end(); it++) {
                        if (index == selected) {
                            (*it)->move_by(10, 0);
                            this->redraw();
                            break;
                        }
                        index++;
                    }
                }
                break;
            case 116:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                if (selected != -1) {
                    int index = 0;
                    for (auto it = shapes.begin(); it != shapes.end(); it++) {
                        if (index == selected) {
                            (*it)->move_by(0, 10);
                            this->redraw();
                            break;
                        }
                        index++;
                    }
                }
                break;
            case 22:  // MUSS NOCH AUF DIE RICHTIGEN CODES GESETZT WERDEN
                if (selected != -1) {
                    this->deleteShape(selected);
                    selected = -1;
                    this->redraw();
                }
                break;

            default:
                break;
        }
        
    }void deleteShape(int pIndex) {
            int index = 0;
            auto it = shapes.begin();
            while (it != shapes.end()) {
                if (index == pIndex) {
                    delete *it;
                    it = shapes.erase(
                        it);  // Lösche das aktuelle Element und erhalte den
                              // Iterator auf das nächste Element zurück
                } else {
                    it++;  // Bewege den Iterator zum nächsten Element
                }
                index++;
            }
        }

   private:
    std::deque<Proku::Shape*> shapes;
    int mousePositionX, mousePositionY;
    int selected;
    bool isMousePressed;
};  // class ShapeWindow

int main() {
    // Erstelle eine neues ShapeWindow
    ShapeWindow window;

    // Rufe die main_loop-Funktion der Basisklasse CanvasWindow auf,
    // welche die Hauptnachrichtenschleife implementiert:
    window.main_loop();

    // Beende das Programm
    return 0;
}