/*
 * -*- coding: utf-8 -*-
 * vim: set fileencoding=utf-8
 *
 * Copyright (c) 2016, Shogun-Toolbox e.V. <shogun-team@shogun-toolbox.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Heiko Strathmann
 */
#ifdef USE_META_INTEGRATION_TESTS
#ifndef WRAPPED_SGVECTOR_H__
#define WRAPPED_SGVECTOR_H__

#include <shogun/base/SGObject.h>
#include <shogun/lib/SGString.h>
#include <shogun/lib/SGVector.h>


namespace shogun
{

/** @brief Simple wrapper class that allows to store any Shogun SGVector<T>
 * in a CSGObject, and therefore to make it serializable. Using a template
 * argument that is not a Shogun parameter will cause a compile error when
 * trying to register the passed value as a parameter in the constructors.
 */
template<class T> class CWrappedSGVector: public CSGObject
{
public:
	/** Default constructor. Do not use. */
	CWrappedSGVector() : CSGObject()
	{
		set_generic<T>();
		register_params();
	}

	/** Constructor.
	 * @param value Value to wrap as CSGObject.
	 * @param value_name Name under which value is registered.
	*/
	CWrappedSGVector(SGVector<T> value, const char* value_name="")
	{
		set_generic<T>();
		register_params();
		m_value = value;
		m_value_name = value_name;
	}

	/** @return name of the CSGObject, without C prefix */
	virtual const char* get_name() const { return "WrappedSGVector"; }

private:
	void register_params()
	{
	    m_value_name = "Unnamed";
	    m_value = SGVector<T>();
	    
		SG_ADD(&m_value, "value", "Wrapped value", MS_NOT_AVAILABLE);
	}

protected:
	/** Wrapped value. */
	SGVector<T> m_value;

	/** Name of wrapped value */
	const char* m_value_name;
};

template class CWrappedSGVector<bool>;
template class CWrappedSGVector<char>;
template class CWrappedSGVector<int8_t>;
template class CWrappedSGVector<uint8_t>;
template class CWrappedSGVector<int16_t>;
template class CWrappedSGVector<uint16_t>;
template class CWrappedSGVector<int32_t>;
template class CWrappedSGVector<uint32_t>;
template class CWrappedSGVector<int64_t>;
template class CWrappedSGVector<uint64_t>;
template class CWrappedSGVector<float32_t>;
template class CWrappedSGVector<float64_t>;
template class CWrappedSGVector<floatmax_t>;

};
#endif // WRAPPED_SGVECTOR_H__
#endif // USE_META_INTEGRATION_TESTS
