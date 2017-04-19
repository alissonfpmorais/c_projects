package br.com.dl.dlpasswordrecover.utils;

import android.accounts.Account;
import android.accounts.AccountManager;
import android.content.Context;

/**
 * Created by Alisson Morais on 24/03/2017.
 */

public class AccountHandler {
    public static final String ACCOUNT_TYPE_GOOGLE = "com.google";

    private Context context;

    private Account[] accounts;
    private String accType;

    public AccountHandler(Context context) {
        this.context = context;
    }

    /**
     * Check if there is any {@link Account} of the type passed
     * @param accType Type of account
     * @return true if there is 1 or more accounts of type passed
     */
    public boolean isThereAccountType(String accType) {
        if(!accType.equals(this.accType)) {
            getAccounts(accType);
        }

        return accounts.length > 0;
    }

    /**
     * Get all {@link Account} logged in device with given type
     * @param accType Type of account
     * @return all {@link Account}
     * @throws SecurityException if no permission are granted before method runs
     */
    public Account[] getAccounts(String accType) throws SecurityException {
        AccountManager accountManager = AccountManager.get(context);
        accounts = accountManager.getAccountsByType(accType);
        this.accType = accType;

        return accounts;
    }
}
