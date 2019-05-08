Resultados_hw2.pdf : Resultados.tex signals.pdf Fourier_trans.pdf Temblor.pdf Fourier_temblor.pdf espectograma_temblor.pdf espectograma.pdf plot_omegafijo.pdf plot_omegas.pdf
    pdflatex Resultados_hw2.tex
signals.pdf: Fourier.py
    python Fourier.py
Fourier_trans.pdf: Fourier.py
    python Fourier.py
espectograma.pdf: Fourier.py
    python Fourier.py
Temblor.pdf: Fourier.py
    python Fourier.py
Fourier_temblor.pdf: Fourier.py
    python Fourier.py
espectograma_temblor.pdf: Fourier.py
    python Fourier.py
plot_omegafijo.pdf: Plots_hw2.py datoslp.dat
    python Plots_hw2.py
%.dat : a.out
    ./a.out
a.out : Edificio.cpp
    g++ Edificio.cpp
plot_omegas.pdf: Plots_hw2.py datos_omega.dat
    python Plots_hw2.py
%.dat : a.out
    ./a.out
a.out : Edificio.cpp
    g++ Edificio.cpp
    

    