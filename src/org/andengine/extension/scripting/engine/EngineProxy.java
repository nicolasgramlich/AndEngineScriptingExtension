package org.andengine.extension.scripting.engine;

import org.andengine.engine.Engine;
import org.andengine.engine.options.EngineOptions;

/**
 * (c) Zynga 2012
 *
 * @author Nicolas Gramlich <ngramlich@zynga.com>
 * @since 15:29:18 - 05.03.2012
 */
public class EngineProxy extends Engine {
	// ===========================================================
	// Constants
	// ===========================================================

	public static native void nativeInitClass();

	// ===========================================================
	// Fields
	// ===========================================================

	private final long mAddress;

	// ===========================================================
	// Constructors
	// ===========================================================

	public EngineProxy(final long pAddress, final EngineOptions pEngineOptions) {
		super(pEngineOptions);

		this.mAddress = pAddress;
	}

	// ===========================================================
	// Getter & Setter
	// ===========================================================

	// ===========================================================
	// Methods for/from SuperClass/Interfaces
	// ===========================================================

	// ===========================================================
	// Methods
	// ===========================================================

	// ===========================================================
	// Inner and Anonymous Classes
	// ===========================================================
}
