package pl.edu.pg.eti.ksg.po.lab1;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.Translacja;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.Skalowanie;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.BrakTransformacjiOdwrotnejException;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.Punkt;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.Transformacja;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.Obrot;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.ZlozenieTransformacji;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.Punkt3D;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.Transformacja3D;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.Translacja3D;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.ObrotOS;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.Obrot3D;
    import pl.edu.pg.eti.ksg.po.lab1.transformacje.ZlozenieTransformacji3D;

//import java.util.Scanner;
public class Javalab1 {
    public static void main(String[] args)
    {
        /*
         * Konstrukcja językowa try {} catch (...){} służy do
         * obsługi wyjątków. Kod w bloku try jest monitorowany
         * pod kątem wystąpienia wyjątku bądź wyjątków
         * wspomnianych na początku bloku/bloków catch.
         * Jeżeli gdzieś w bloku try wystąpi wyjątek, to sterowanie
         * zostanie natychmiast przeniesione do bloku catch.
         * Tam powinien znajdować się kod obsługujący wyjątek.
         * Może to być np. wypisanie stosu wywołań na wyjście błędów
         * lub zapisanie wyjątku w logach, lub wyrzucenie (zgłoszenie)
         * innego wyjątku lepiej opisującego sytuacje (można załączyć
         * wyjątek który zainicjował to zdarzenie patrz. Konstruktor
         * klasy java.lang.Exception)
         */
        try {
            Punkt p1 = Punkt.E_X;
            System.out.println(p1);
            Transformacja tr = new Translacja(5, 6);
            System.out.println(tr);
            Punkt p2 = tr.transformuj(p1);
            System.out.println(p2);
            Transformacja trr = tr.getTransformacjaOdwrotna();
            System.out.println(trr);
            Punkt p3 = trr.transformuj(p2);
            System.out.println(p3);
        } catch (BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();
        try
        {
            Punkt p1 = new Punkt(2, 2);
            System.out.println(p1);
            Transformacja tr2 = new Skalowanie(5, 4);
            System.out.println(tr2);
            Punkt p2 = tr2.transformuj(p1);
            System.out.println(p2);
            Transformacja trr2 = tr2.getTransformacjaOdwrotna();
            System.out.println(trr2);
            Punkt p3 = trr2.transformuj(p2);
            System.out.println(p3);
        }
        catch(BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();
        try
        {
            Punkt p1 = new Punkt(2, 2);
            Transformacja tr2 = new Skalowanie(5, 0);
            System.out.println(tr2);
            System.out.println(p1);
            Punkt p2 = tr2.transformuj(p1);
            System.out.println(p2);
            Transformacja trr2 = tr2.getTransformacjaOdwrotna();
            System.out.println(trr2);
            Punkt p3 = trr2.transformuj(p2);
            System.out.println(p3);
        }
        catch(BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();

        try {
            Punkt p1 = new Punkt(2, 2);
            System.out.println(p1);
            Transformacja tr = new Obrot(3.141592653);
            System.out.println(tr);
            Punkt p2 = tr.transformuj(p1);
            System.out.println(p2);
            Transformacja trr = tr.getTransformacjaOdwrotna();
            System.out.println(trr);
            Punkt p3 = trr.transformuj(p2);
            System.out.println(p3);
        } catch (BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();

        try {
            Punkt p1 = new Punkt(2, 2);
            System.out.println(p1);
            ZlozenieTransformacji zt = new ZlozenieTransformacji(3);
            //System.out.println(zt);
            zt.tab[0] = new Obrot(3.141592653);
            zt.tab[1] = new Skalowanie(5, 2);
            zt.tab[2] = new Translacja(5, 6);
            Punkt p2 = zt.transformuj(p1);
            System.out.println(p2);
            Transformacja zt2 = zt.getTransformacjaOdwrotna();
            Punkt p3 = zt2.transformuj(p2);
            System.out.println(p3);
        } catch (BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();

        try {
            Punkt3D p1 = new Punkt3D(2, 2, 2);
            System.out.println(p1);
            ObrotOS o1 = new ObrotOS('z', 3.141592653);
            Punkt3D p2 = o1.transformuj3D(p1);
            System.out.println(p2);
            Obrot3D o2 = new Obrot3D(3.141592653, 0, 1.8);
            Punkt3D p3 = o2.transformuj(p2);
            System.out.println(p3);
            ZlozenieTransformacji3D zt = new ZlozenieTransformacji3D(2);
            zt.tab[0] = new Obrot3D(3.141592653, 0, 1.8);
            zt.tab[1] = new Translacja3D(5, 2, 7);
            Punkt p4 = zt.transformuj3D(p3);
            System.out.println(p4);

        } catch (BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();
    }
}