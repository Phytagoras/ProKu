#include <deque>

#include "canvas_window.hpp"
#include "shape.hpp"

// TODO: Fuell mich mit Leben!

class Rectangle : Shape {
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
    void draw(Proku::Canvas& canvas) override {
        canvas.select_color(0, 0, 0);
        canvas.draw_rect(x, y, breite, hoehe);
    }
    bool hit_test(int px, int py) override {
        return (px > x && px < x + breite && py > y && py < y + hoehe);
    }
    void move_by(int dx, int dy) override {
        x = x + dx;
        y = y + dy;
    }
};
class Circle : Shape {
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
    void draw(Proku::Canvas& canvas) override {
        canvas.select_color(0, 0, 0);
        canvas.draw_circle(x, y, radius);
    }
    bool hit_test(int px, int py) override {
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

        for (auto it = shapes.begin(); it != shapes.end(); it++) {
            *it.draw(this);
        }

        // Beende Zeichnung
        this->paint_finish();
    }
    virtual void on_mouse_button(int x, int y, int button,
                                 bool pressed) override {
        for (auto it = shapes.begin(); it != shapes.end(); it++) {
            *it.test_hit()  ///////////////////////////////////////////////HIER
                            ///WEITERMACHEN
        }
    }

   private:
    std::deque<Shape*> shapes;
    int selected;
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