#ifndef EXPOSE_H
#define EXPOSE_H

#include <QWidget>
#include <canvas.h>

namespace Ui {
    class Expose;
}

class Expose : public QWidget
{
    Q_OBJECT

public:
    explicit Expose(Canvas *canvas, QWidget *parent = 0);
    ~Expose();

    static void DrawData(QPixmap& pixmap, std::vector<fvec> samples, ivec labels, int type, bool bProjected=false);
    static void DrawData(QPixmap& pixmap, std::vector<fvec> samples, std::vector<QColor> sampleColors, int type, bool bProjected=false);
    static void DrawVariableData(QPixmap& pixmap, std::vector<fvec> samples, ivec labels, int type, fvec params, bool bProjected=false);
    static void DrawVariableData(QPixmap& pixmap, std::vector<fvec> samples, std::vector<QColor> sampleColors, int type, fvec params, bool bProjected=false);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent( QResizeEvent *event );

private:
    void GenerateScatterPlot(bool bCheckOnly=false);
    void GenerateParallelCoords();
    void GenerateRadialGraph();
    void GenerateAndrewsPlots();

private slots:
    void Clipboard();
    void Repaint();

private:
    Ui::Expose *ui;
    Canvas *canvas;
    QPixmap pixmap;
};

#endif // EXPOSE_H
