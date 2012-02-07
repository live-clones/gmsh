package org.geuz.gmsh.utils;

import java.lang.reflect.Method;
import java.util.AbstractSet;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

/**
 * Wrapper for std::set and std::list from SWIG. This does not support removal
 * during iteration.
 * 
 * @author Chad Retz
 * 
 * @param <T>
 */
public class NativeSet<T> extends AbstractSet<T> implements Set<T> {
    
    private final Class<T> nativeClass;
    private final Class<?> setIteratorClass;
    private final Object nativeSet;
    private final Object setWrapper;
    private final Method sizeMethod;
    private final Method containsMethod;
    private final Method addMethod;
    private final Method clearMethod;
    private final Method removeMethod;
    private final Method hasNextMethod;
    private final Method nextMethod;
    
    /**
     * Instantiate the native set
     * 
     * @param nativeClass
     *            The native class
     * @param setIteratorClass
     *            The class for the SetIterator
     * @param nativeSet
     *            The native set object
     * @param setWrapperClass
     *            The class for the Set
     */
    public NativeSet(final Class<T> nativeClass, final Class<?> setIteratorClass, final Object nativeSet, final Class<?> setWrapperClass) {
        this.nativeClass = nativeClass;
        this.setIteratorClass = setIteratorClass;
        this.nativeSet = nativeSet;
        try {
            this.setWrapper = setWrapperClass.getConstructor(nativeSet.getClass()).newInstance(nativeSet);
            this.sizeMethod = setWrapperClass.getDeclaredMethod("size");
            this.containsMethod = setWrapperClass.getDeclaredMethod("contains", nativeClass);
            this.addMethod = setWrapperClass.getDeclaredMethod("add", nativeClass);
            this.clearMethod = setWrapperClass.getDeclaredMethod("clear");
            this.removeMethod = setWrapperClass.getDeclaredMethod("remove", nativeClass);
            this.hasNextMethod = setIteratorClass.getDeclaredMethod("hasNext");
            this.nextMethod = setIteratorClass.getDeclaredMethod("next");
        } catch (final Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    @Override
    public boolean add(final T item) {
        try {
            return (Boolean) this.addMethod.invoke(this.setWrapper, item);
        } catch (final Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    @Override
    public void clear() {
        try {
            this.clearMethod.invoke(this.setWrapper);
        } catch (final Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    @Override
    public boolean contains(final Object item) {
        try {
            return this.nativeClass.isAssignableFrom(item.getClass()) && (Boolean) this.containsMethod.invoke(this.setWrapper, item);
        } catch (final Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    @Override
    public Iterator<T> iterator() {
        return new NativeSetIterator();
    }
    
    @Override
    public boolean remove(final Object item) {
        try {
            return (Boolean) this.removeMethod.invoke(this.setWrapper, item);
        } catch (final Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    @Override
    public boolean removeAll(final Collection<?> collection) {
        boolean modified = false;
        for (final Object item : collection) {
            modified |= this.remove(item);
        }
        return modified;
    }
    
    @Override
    public boolean retainAll(final Collection<?> collection) {
        // best way?
        final List<T> toRemove = new ArrayList<T>(this.size());
        for (final T item : this) {
            if (!collection.contains(item)) {
                toRemove.add(item);
            }
        }
        return this.removeAll(toRemove);
    }
    
    @Override
    public int size() {
        try {
            return (Integer) this.sizeMethod.invoke(this.setWrapper);
        } catch (final Exception e) {
            throw new RuntimeException(e);
        }
    }
    
    protected class NativeSetIterator implements Iterator<T> {
        
        private final Object setIterator;
        
        private NativeSetIterator() {
            try {
                this.setIterator = NativeSet.this.setIteratorClass.getConstructor(NativeSet.this.nativeSet.getClass()).newInstance(NativeSet.this.nativeSet);
            } catch (final Exception e) {
                throw new RuntimeException(e);
            }
        }
        
        @Override
        public boolean hasNext() {
            try {
                return (Boolean) NativeSet.this.hasNextMethod.invoke(this.setIterator);
            } catch (final Exception e) {
                throw new RuntimeException(e);
            }
        }
        
        @Override
        @SuppressWarnings("unchecked")
        public T next() {
            try {
                return (T) NativeSet.this.nextMethod.invoke(this.setIterator);
            } catch (final Exception e) {
                throw new RuntimeException(e);
            }
        }
        
        /**
         * {@inheritDoc}
         * <p>
         * Unsupported
         */
        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
        
    }
}
