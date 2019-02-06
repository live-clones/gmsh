package org.geuz.gmsh.utils;
 
import java.lang.reflect.Method;
import java.util.AbstractList;
import java.util.List;
 
/**
 * Wrapper for std::vector from SWIG
 *
 * @author Chad Retz
 *
 * @param <T>
 */
public class NativeList<T> extends AbstractList<T> implements List<T> {
 
    private final Object listWrapper;
    private final Method sizeMethod;
    private final Method addMethod;
    private final Method clearMethod;
    private final Method setMethod;
    private final Method removeMethod;
    private final Method getMethod;
 
    /**
     * Construct native list from std::vector wrappers
     *
     * @param nativeClass The native class
     * @param nativeList The SWIG vector
     * @param listWrapperClass The SWIG vector class wrapper
     */
    public NativeList(Class<T> nativeClass, Object nativeList, Class<?> listWrapperClass) {
        try {
            listWrapper = listWrapperClass.getConstructor(nativeList.getClass()).
                    newInstance(nativeList);
            sizeMethod = listWrapperClass.getDeclaredMethod("size");
            addMethod = listWrapperClass.getDeclaredMethod("add",
                    Integer.TYPE, nativeClass);
            clearMethod = listWrapperClass.getDeclaredMethod("clear");
            setMethod = listWrapperClass.getDeclaredMethod("set",
                    Integer.TYPE, nativeClass);
            removeMethod = listWrapperClass.getDeclaredMethod("remove", Integer.TYPE);
            getMethod = listWrapperClass.getDeclaredMethod("get", Integer.TYPE);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
 
    @Override
    public void add(int index, T item) {
        try {
            addMethod.invoke(listWrapper, index, item);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
 
    @Override
    public void clear() {
        try {
            clearMethod.invoke(listWrapper);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
 
    @Override
    @SuppressWarnings("unchecked")
    public T set(int index, T item) {
        try {
            return (T) setMethod.invoke(listWrapper, index, item);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
 
    @Override
    @SuppressWarnings("unchecked")
    public T remove(int index) {
        try {
            return (T) removeMethod.invoke(listWrapper, index);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
 
    @Override
    public boolean remove(Object item) {
        try {
            return (Boolean) removeMethod.invoke(listWrapper, item);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
 
    @Override
    @SuppressWarnings("unchecked")
    public T get(int index) {
        try {
            return (T) getMethod.invoke(listWrapper, index);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
 
    @Override
    public int size() {
        try {
            return (Integer) sizeMethod.invoke(listWrapper);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
