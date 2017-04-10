package br.com.manual_pdf.utils;

/**
 * Created by Álisson Morais on 23/03/2017.
 */
public interface Executable {
    void onPermissionGranted();
    void onPermissionDenied();
}
