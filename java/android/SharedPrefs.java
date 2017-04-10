package br.com.manual_pdf.utils;

import android.content.Context;
import android.content.SharedPreferences;

import static android.content.Context.MODE_PRIVATE;

/**
 * Created by Álisson Morais on 24/03/2017.
 */

public class SharedPrefs {
    private Context context;

    public SharedPrefs(Context context) {
        this.context = context;
    }

    /**
     * Get {@link SharedPreferences} with specified PREFS_NAME and MODE_PRIVATE
     * @return {@link SharedPreferences} instance
     */
    private SharedPreferences getSharedPrefs(String prefsName) {
        return context.getSharedPreferences(prefsName, MODE_PRIVATE);
    }

    /**
     * Clear {@link SharedPreferences}
     */
    public void clearPrefs(String prefsName) {
        SharedPreferences.Editor editor = getSharedPrefs(prefsName).edit();

        editor.clear();
        editor.apply();
    }

    /**
     * Get a {@link String} of the given key
     * @param prefsName name of shared preferences
     * @param key of wanted {@link String}
     * @param defValue if no String are found in {@link SharedPreferences}, return this value
     * @return {@link String} found or default value
     */
    public String getPrefsString(String prefsName, String key, String defValue) {
        return getSharedPrefs(prefsName).getString(key, defValue);
    }

    /**
     * Set new {@link String} to {@link SharedPreferences}
     * @param prefsName name of shared preferences
     * @param key to save new preference
     * @param value of preference
     */
    public void setPrefsString(String prefsName, String key, String value) {
        SharedPreferences.Editor editor = getSharedPrefs(prefsName).edit();

        editor.putString(key, value);
        editor.apply();
    }

    /**
     * Get a {@link Integer} of the given key
     * @param prefsName name of shared preferences
     * @param key of wanted {@link Integer}
     * @param defValue if no int are found in {@link SharedPreferences}, return this value
     * @return {@link Integer} found or default value
     */
    public int getPrefsInt(String prefsName, String key, int defValue) {
        return getSharedPrefs(prefsName).getInt(key, defValue);
    }

    /**
     * Set new {@link Integer} to {@link SharedPreferences}
     * @param prefsName name of shared preferences
     * @param key to save new preference
     * @param value of preference
     */
    public void setPrefsInt(String prefsName, String key, int value) {
        SharedPreferences.Editor editor = getSharedPrefs(prefsName).edit();

        editor.putInt(key, value);
        editor.apply();
    }

    /**
     * Get a {@link Boolean} of the given key
     * @param prefsName name of shared preferences
     * @param key of wanted {@link Boolean}
     * @param defValue if no boolean are found in {@link SharedPreferences}, return this value
     * @return {@link Boolean} found or default value
     */
    public boolean getPrefsBoolean(String prefsName, String key, boolean defValue) {
        return getSharedPrefs(prefsName).getBoolean(key, defValue);
    }

    /**
     * Set new {@link Boolean} to {@link SharedPreferences}
     * @param prefsName name of shared preferences
     * @param key to save new preference
     * @param value of preference
     */
    public void setPrefsBoolean(String prefsName, String key, boolean value) {
        SharedPreferences.Editor editor = getSharedPrefs(prefsName).edit();

        editor.putBoolean(key, value);
        editor.apply();
    }
}
