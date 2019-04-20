Resultados_hw2.pdf : resultados.tex signals.pdf Fourier_trans.pdf Temblor.pdf Fourier_temblor.pdf plot.pdf
    pdflatex Resultados_hw2.tex
signals.pdf: Fourier.py
    python Fourier.py
Fourier_trans.pdf: Fourier.py
    python Fourier.py
Temblor.pdf: Fourier.py
    python Fourier.py
Fourier_temblor.pdf: Fourier.py
    python Fourier.py
plot.pdf : Plots_hw2.py datos.dat
    python plot_hw2.py
datos.dat : a.out
    ./a.out >> datos. dat
a.out : makedatos.cpp
    g++ makedatos.cpp