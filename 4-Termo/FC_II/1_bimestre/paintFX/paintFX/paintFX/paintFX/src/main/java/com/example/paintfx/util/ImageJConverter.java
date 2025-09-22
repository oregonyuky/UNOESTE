package com.example.paintfx.util;

import ij.IJ;
import ij.ImagePlus;
import ij.process.ImageProcessor;
import javafx.embed.swing.SwingFXUtils;
import javafx.scene.image.Image;

import java.awt.image.BufferedImage;

public class ImageJConverter {

    public static Image findEdges(Image image) {
        ImagePlus imp = new ImagePlus("temp", SwingFXUtils.fromFXImage(image, null));
        IJ.run(imp, "Find Edges", "");
        ImageProcessor ip = imp.getProcessor();
        BufferedImage out = ip.getBufferedImage();
        return SwingFXUtils.toFXImage(out, null);
    }

    public static Image sharpen(Image image) {
        ImagePlus imp = new ImagePlus("temp", SwingFXUtils.fromFXImage(image, null));
        IJ.run(imp, "Sharpen", "");
        ImageProcessor ip = imp.getProcessor();
        BufferedImage out = ip.getBufferedImage();
        return SwingFXUtils.toFXImage(out, null);
    }

    public static Image gaussianBlur(Image image, double sigma) {
        ImagePlus imp = new ImagePlus("temp", SwingFXUtils.fromFXImage(image, null));
        IJ.run(imp, "Gaussian Blur...", "sigma=" + sigma);
        ImageProcessor ip = imp.getProcessor();
        BufferedImage out = ip.getBufferedImage();
        return SwingFXUtils.toFXImage(out, null);
    }

    public static Image equalizeHistogram(Image image) {
        ImagePlus imp = new ImagePlus("temp", SwingFXUtils.fromFXImage(image, null));
        IJ.run(imp, "Enhance Contrast", "saturated=0.35 equalize");
        ImageProcessor ip = imp.getProcessor();
        BufferedImage out = ip.getBufferedImage();
        return SwingFXUtils.toFXImage(out, null);
    }

    public static Image noise(Image image, int fator) {
        ImagePlus imp = new ImagePlus("temp", SwingFXUtils.fromFXImage(image, null));
        ImageProcessor ip = imp.getProcessor();
        ip.noise(fator);
        return SwingFXUtils.toFXImage(imp.getBufferedImage(), null);
    }
}
