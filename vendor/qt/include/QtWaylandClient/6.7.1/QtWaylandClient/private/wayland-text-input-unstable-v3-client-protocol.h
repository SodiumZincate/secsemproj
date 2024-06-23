/* Generated by wayland-scanner 1.22.0 */

#ifndef TEXT_INPUT_UNSTABLE_V3_CLIENT_PROTOCOL_H
#define TEXT_INPUT_UNSTABLE_V3_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client-core.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_text_input_unstable_v3 The text_input_unstable_v3 protocol
 * Protocol for composing text
 *
 * @section page_desc_text_input_unstable_v3 Description
 *
 * This protocol allows compositors to act as input methods and to send text
 * to applications. A text input object is used to manage state of what are
 * typically text entry fields in the application.
 *
 * This document adheres to the RFC 2119 when using words like "must",
 * "should", "may", etc.
 *
 * Warning! The protocol described in this file is experimental and
 * backward incompatible changes may be made. Backward compatible changes
 * may be added together with the corresponding interface version bump.
 * Backward incompatible changes are done by bumping the version number in
 * the protocol and interface names and resetting the interface version.
 * Once the protocol is to be declared stable, the 'z' prefix and the
 * version number in the protocol and interface names are removed and the
 * interface version number is reset.
 *
 * @section page_ifaces_text_input_unstable_v3 Interfaces
 * - @subpage page_iface_zwp_text_input_v3 - text input
 * - @subpage page_iface_zwp_text_input_manager_v3 - text input manager
 * @section page_copyright_text_input_unstable_v3 Copyright
 * <pre>
 *
 * Copyright © 2012, 2013 Intel Corporation
 * Copyright © 2015, 2016 Jan Arne Petersen
 * Copyright © 2017, 2018 Red Hat, Inc.
 * Copyright © 2018       Purism SPC
 *
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 * </pre>
 */
struct wl_seat;
struct wl_surface;
struct zwp_text_input_manager_v3;
struct zwp_text_input_v3;

#ifndef ZWP_TEXT_INPUT_V3_INTERFACE
#define ZWP_TEXT_INPUT_V3_INTERFACE
/**
 * @page page_iface_zwp_text_input_v3 zwp_text_input_v3
 * @section page_iface_zwp_text_input_v3_desc Description
 *
 * The zwp_text_input_v3 interface represents text input and input methods
 * associated with a seat. It provides enter/leave events to follow the
 * text input focus for a seat.
 *
 * Requests are used to enable/disable the text-input object and set
 * state information like surrounding and selected text or the content type.
 * The information about the entered text is sent to the text-input object
 * via the preedit_string and commit_string events.
 *
 * Text is valid UTF-8 encoded, indices and lengths are in bytes. Indices
 * must not point to middle bytes inside a code point: they must either
 * point to the first byte of a code point or to the end of the buffer.
 * Lengths must be measured between two valid indices.
 *
 * Focus moving throughout surfaces will result in the emission of
 * zwp_text_input_v3.enter and zwp_text_input_v3.leave events. The focused
 * surface must commit zwp_text_input_v3.enable and
 * zwp_text_input_v3.disable requests as the keyboard focus moves across
 * editable and non-editable elements of the UI. Those two requests are not
 * expected to be paired with each other, the compositor must be able to
 * handle consecutive series of the same request.
 *
 * State is sent by the state requests (set_surrounding_text,
 * set_content_type and set_cursor_rectangle) and a commit request. After an
 * enter event or disable request all state information is invalidated and
 * needs to be resent by the client.
 * @section page_iface_zwp_text_input_v3_api API
 * See @ref iface_zwp_text_input_v3.
 */
/**
 * @defgroup iface_zwp_text_input_v3 The zwp_text_input_v3 interface
 *
 * The zwp_text_input_v3 interface represents text input and input methods
 * associated with a seat. It provides enter/leave events to follow the
 * text input focus for a seat.
 *
 * Requests are used to enable/disable the text-input object and set
 * state information like surrounding and selected text or the content type.
 * The information about the entered text is sent to the text-input object
 * via the preedit_string and commit_string events.
 *
 * Text is valid UTF-8 encoded, indices and lengths are in bytes. Indices
 * must not point to middle bytes inside a code point: they must either
 * point to the first byte of a code point or to the end of the buffer.
 * Lengths must be measured between two valid indices.
 *
 * Focus moving throughout surfaces will result in the emission of
 * zwp_text_input_v3.enter and zwp_text_input_v3.leave events. The focused
 * surface must commit zwp_text_input_v3.enable and
 * zwp_text_input_v3.disable requests as the keyboard focus moves across
 * editable and non-editable elements of the UI. Those two requests are not
 * expected to be paired with each other, the compositor must be able to
 * handle consecutive series of the same request.
 *
 * State is sent by the state requests (set_surrounding_text,
 * set_content_type and set_cursor_rectangle) and a commit request. After an
 * enter event or disable request all state information is invalidated and
 * needs to be resent by the client.
 */
extern const struct wl_interface zwp_text_input_v3_interface;
#endif
#ifndef ZWP_TEXT_INPUT_MANAGER_V3_INTERFACE
#define ZWP_TEXT_INPUT_MANAGER_V3_INTERFACE
/**
 * @page page_iface_zwp_text_input_manager_v3 zwp_text_input_manager_v3
 * @section page_iface_zwp_text_input_manager_v3_desc Description
 *
 * A factory for text-input objects. This object is a global singleton.
 * @section page_iface_zwp_text_input_manager_v3_api API
 * See @ref iface_zwp_text_input_manager_v3.
 */
/**
 * @defgroup iface_zwp_text_input_manager_v3 The zwp_text_input_manager_v3 interface
 *
 * A factory for text-input objects. This object is a global singleton.
 */
extern const struct wl_interface zwp_text_input_manager_v3_interface;
#endif

#ifndef ZWP_TEXT_INPUT_V3_CHANGE_CAUSE_ENUM
#define ZWP_TEXT_INPUT_V3_CHANGE_CAUSE_ENUM
/**
 * @ingroup iface_zwp_text_input_v3
 * text change reason
 *
 * Reason for the change of surrounding text or cursor posision.
 */
enum zwp_text_input_v3_change_cause {
	/**
	 * input method caused the change
	 */
	ZWP_TEXT_INPUT_V3_CHANGE_CAUSE_INPUT_METHOD = 0,
	/**
	 * something else than the input method caused the change
	 */
	ZWP_TEXT_INPUT_V3_CHANGE_CAUSE_OTHER = 1,
};
#endif /* ZWP_TEXT_INPUT_V3_CHANGE_CAUSE_ENUM */

#ifndef ZWP_TEXT_INPUT_V3_CONTENT_HINT_ENUM
#define ZWP_TEXT_INPUT_V3_CONTENT_HINT_ENUM
/**
 * @ingroup iface_zwp_text_input_v3
 * content hint
 *
 * Content hint is a bitmask to allow to modify the behavior of the text
 * input.
 */
enum zwp_text_input_v3_content_hint {
	/**
	 * no special behavior
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_NONE = 0x0,
	/**
	 * suggest word completions
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_COMPLETION = 0x1,
	/**
	 * suggest word corrections
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_SPELLCHECK = 0x2,
	/**
	 * switch to uppercase letters at the start of a sentence
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_AUTO_CAPITALIZATION = 0x4,
	/**
	 * prefer lowercase letters
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_LOWERCASE = 0x8,
	/**
	 * prefer uppercase letters
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_UPPERCASE = 0x10,
	/**
	 * prefer casing for titles and headings (can be language dependent)
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_TITLECASE = 0x20,
	/**
	 * characters should be hidden
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_HIDDEN_TEXT = 0x40,
	/**
	 * typed text should not be stored
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_SENSITIVE_DATA = 0x80,
	/**
	 * just Latin characters should be entered
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_LATIN = 0x100,
	/**
	 * the text input is multiline
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_HINT_MULTILINE = 0x200,
};
#endif /* ZWP_TEXT_INPUT_V3_CONTENT_HINT_ENUM */

#ifndef ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_ENUM
#define ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_ENUM
/**
 * @ingroup iface_zwp_text_input_v3
 * content purpose
 *
 * The content purpose allows to specify the primary purpose of a text
 * input.
 *
 * This allows an input method to show special purpose input panels with
 * extra characters or to disallow some characters.
 */
enum zwp_text_input_v3_content_purpose {
	/**
	 * default input, allowing all characters
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_NORMAL = 0,
	/**
	 * allow only alphabetic characters
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_ALPHA = 1,
	/**
	 * allow only digits
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_DIGITS = 2,
	/**
	 * input a number (including decimal separator and sign)
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_NUMBER = 3,
	/**
	 * input a phone number
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_PHONE = 4,
	/**
	 * input an URL
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_URL = 5,
	/**
	 * input an email address
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_EMAIL = 6,
	/**
	 * input a name of a person
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_NAME = 7,
	/**
	 * input a password (combine with sensitive_data hint)
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_PASSWORD = 8,
	/**
	 * input is a numeric password (combine with sensitive_data hint)
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_PIN = 9,
	/**
	 * input a date
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_DATE = 10,
	/**
	 * input a time
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_TIME = 11,
	/**
	 * input a date and time
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_DATETIME = 12,
	/**
	 * input for a terminal
	 */
	ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_TERMINAL = 13,
};
#endif /* ZWP_TEXT_INPUT_V3_CONTENT_PURPOSE_ENUM */

/**
 * @ingroup iface_zwp_text_input_v3
 * @struct zwp_text_input_v3_listener
 */
struct zwp_text_input_v3_listener {
	/**
	 * enter event
	 *
	 * Notification that this seat's text-input focus is on a certain
	 * surface.
	 *
	 * If client has created multiple text input objects, compositor
	 * must send this event to all of them.
	 *
	 * When the seat has the keyboard capability the text-input focus
	 * follows the keyboard focus. This event sets the current surface
	 * for the text-input object.
	 */
	void (*enter)(void *data,
		      struct zwp_text_input_v3 *zwp_text_input_v3,
		      struct wl_surface *surface);
	/**
	 * leave event
	 *
	 * Notification that this seat's text-input focus is no longer on
	 * a certain surface. The client should reset any preedit string
	 * previously set.
	 *
	 * The leave notification clears the current surface. It is sent
	 * before the enter notification for the new focus. After leave
	 * event, compositor must ignore requests from any text input
	 * instances until next enter event.
	 *
	 * When the seat has the keyboard capability the text-input focus
	 * follows the keyboard focus.
	 */
	void (*leave)(void *data,
		      struct zwp_text_input_v3 *zwp_text_input_v3,
		      struct wl_surface *surface);
	/**
	 * pre-edit
	 *
	 * Notify when a new composing text (pre-edit) should be set at
	 * the current cursor position. Any previously set composing text
	 * must be removed. Any previously existing selected text must be
	 * removed.
	 *
	 * The argument text contains the pre-edit string buffer.
	 *
	 * The parameters cursor_begin and cursor_end are counted in bytes
	 * relative to the beginning of the submitted text buffer. Cursor
	 * should be hidden when both are equal to -1.
	 *
	 * They could be represented by the client as a line if both values
	 * are the same, or as a text highlight otherwise.
	 *
	 * Values set with this event are double-buffered. They must be
	 * applied and reset to initial on the next zwp_text_input_v3.done
	 * event.
	 *
	 * The initial value of text is an empty string, and cursor_begin,
	 * cursor_end and cursor_hidden are all 0.
	 */
	void (*preedit_string)(void *data,
			       struct zwp_text_input_v3 *zwp_text_input_v3,
			       const char *text,
			       int32_t cursor_begin,
			       int32_t cursor_end);
	/**
	 * text commit
	 *
	 * Notify when text should be inserted into the editor widget.
	 * The text to commit could be either just a single character after
	 * a key press or the result of some composing (pre-edit).
	 *
	 * Values set with this event are double-buffered. They must be
	 * applied and reset to initial on the next zwp_text_input_v3.done
	 * event.
	 *
	 * The initial value of text is an empty string.
	 */
	void (*commit_string)(void *data,
			      struct zwp_text_input_v3 *zwp_text_input_v3,
			      const char *text);
	/**
	 * delete surrounding text
	 *
	 * Notify when the text around the current cursor position should
	 * be deleted.
	 *
	 * Before_length and after_length are the number of bytes before
	 * and after the current cursor index (excluding the selection) to
	 * delete.
	 *
	 * If a preedit text is present, in effect before_length is counted
	 * from the beginning of it, and after_length from its end (see
	 * done event sequence).
	 *
	 * Values set with this event are double-buffered. They must be
	 * applied and reset to initial on the next zwp_text_input_v3.done
	 * event.
	 *
	 * The initial values of both before_length and after_length are 0.
	 * @param before_length length of text before current cursor position
	 * @param after_length length of text after current cursor position
	 */
	void (*delete_surrounding_text)(void *data,
					struct zwp_text_input_v3 *zwp_text_input_v3,
					uint32_t before_length,
					uint32_t after_length);
	/**
	 * apply changes
	 *
	 * Instruct the application to apply changes to state requested
	 * by the preedit_string, commit_string and delete_surrounding_text
	 * events. The state relating to these events is double-buffered,
	 * and each one modifies the pending state. This event replaces the
	 * current state with the pending state.
	 *
	 * The application must proceed by evaluating the changes in the
	 * following order:
	 *
	 * 1. Replace existing preedit string with the cursor. 2. Delete
	 * requested surrounding text. 3. Insert commit string with the
	 * cursor at its end. 4. Calculate surrounding text to send. 5.
	 * Insert new preedit text in cursor position. 6. Place cursor
	 * inside preedit text.
	 *
	 * The serial number reflects the last state of the
	 * zwp_text_input_v3 object known to the compositor. The value of
	 * the serial argument must be equal to the number of commit
	 * requests already issued on that object.
	 *
	 * When the client receives a done event with a serial different
	 * than the number of past commit requests, it must proceed with
	 * evaluating and applying the changes as normal, except it should
	 * not change the current state of the zwp_text_input_v3 object.
	 * All pending state requests (set_surrounding_text,
	 * set_content_type and set_cursor_rectangle) on the
	 * zwp_text_input_v3 object should be sent and committed after
	 * receiving a zwp_text_input_v3.done event with a matching serial.
	 */
	void (*done)(void *data,
		     struct zwp_text_input_v3 *zwp_text_input_v3,
		     uint32_t serial);
};

/**
 * @ingroup iface_zwp_text_input_v3
 */
static inline int
zwp_text_input_v3_add_listener(struct zwp_text_input_v3 *zwp_text_input_v3,
			       const struct zwp_text_input_v3_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zwp_text_input_v3,
				     (void (**)(void)) listener, data);
}

#define ZWP_TEXT_INPUT_V3_DESTROY 0
#define ZWP_TEXT_INPUT_V3_ENABLE 1
#define ZWP_TEXT_INPUT_V3_DISABLE 2
#define ZWP_TEXT_INPUT_V3_SET_SURROUNDING_TEXT 3
#define ZWP_TEXT_INPUT_V3_SET_TEXT_CHANGE_CAUSE 4
#define ZWP_TEXT_INPUT_V3_SET_CONTENT_TYPE 5
#define ZWP_TEXT_INPUT_V3_SET_CURSOR_RECTANGLE 6
#define ZWP_TEXT_INPUT_V3_COMMIT 7

/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_ENTER_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_LEAVE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_PREEDIT_STRING_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_COMMIT_STRING_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_DELETE_SURROUNDING_TEXT_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_DONE_SINCE_VERSION 1

/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_ENABLE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_DISABLE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_SET_SURROUNDING_TEXT_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_SET_TEXT_CHANGE_CAUSE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_SET_CONTENT_TYPE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_SET_CURSOR_RECTANGLE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v3
 */
#define ZWP_TEXT_INPUT_V3_COMMIT_SINCE_VERSION 1

/** @ingroup iface_zwp_text_input_v3 */
static inline void
zwp_text_input_v3_set_user_data(struct zwp_text_input_v3 *zwp_text_input_v3, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwp_text_input_v3, user_data);
}

/** @ingroup iface_zwp_text_input_v3 */
static inline void *
zwp_text_input_v3_get_user_data(struct zwp_text_input_v3 *zwp_text_input_v3)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwp_text_input_v3);
}

static inline uint32_t
zwp_text_input_v3_get_version(struct zwp_text_input_v3 *zwp_text_input_v3)
{
	return wl_proxy_get_version((struct wl_proxy *) zwp_text_input_v3);
}

/**
 * @ingroup iface_zwp_text_input_v3
 *
 * Destroy the wp_text_input object. Also disables all surfaces enabled
 * through this wp_text_input object.
 */
static inline void
zwp_text_input_v3_destroy(struct zwp_text_input_v3 *zwp_text_input_v3)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_text_input_v3,
			 ZWP_TEXT_INPUT_V3_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_text_input_v3), WL_MARSHAL_FLAG_DESTROY);
}

/**
 * @ingroup iface_zwp_text_input_v3
 *
 * Requests text input on the surface previously obtained from the enter
 * event.
 *
 * This request must be issued every time the active text input changes
 * to a new one, including within the current surface. Use
 * zwp_text_input_v3.disable when there is no longer any input focus on
 * the current surface.
 *
 * Clients must not enable more than one text input on the single seat
 * and should disable the current text input before enabling the new one.
 * At most one instance of text input may be in enabled state per instance,
 * Requests to enable the another text input when some text input is active
 * must be ignored by compositor.
 *
 * This request resets all state associated with previous enable, disable,
 * set_surrounding_text, set_text_change_cause, set_content_type, and
 * set_cursor_rectangle requests, as well as the state associated with
 * preedit_string, commit_string, and delete_surrounding_text events.
 *
 * The set_surrounding_text, set_content_type and set_cursor_rectangle
 * requests must follow if the text input supports the necessary
 * functionality.
 *
 * State set with this request is double-buffered. It will get applied on
 * the next zwp_text_input_v3.commit request, and stay valid until the
 * next committed enable or disable request.
 *
 * The changes must be applied by the compositor after issuing a
 * zwp_text_input_v3.commit request.
 */
static inline void
zwp_text_input_v3_enable(struct zwp_text_input_v3 *zwp_text_input_v3)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_text_input_v3,
			 ZWP_TEXT_INPUT_V3_ENABLE, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_text_input_v3), 0);
}

/**
 * @ingroup iface_zwp_text_input_v3
 *
 * Explicitly disable text input on the current surface (typically when
 * there is no focus on any text entry inside the surface).
 *
 * State set with this request is double-buffered. It will get applied on
 * the next zwp_text_input_v3.commit request.
 */
static inline void
zwp_text_input_v3_disable(struct zwp_text_input_v3 *zwp_text_input_v3)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_text_input_v3,
			 ZWP_TEXT_INPUT_V3_DISABLE, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_text_input_v3), 0);
}

/**
 * @ingroup iface_zwp_text_input_v3
 *
 * Sets the surrounding plain text around the input, excluding the preedit
 * text.
 *
 * The client should notify the compositor of any changes in any of the
 * values carried with this request, including changes caused by handling
 * incoming text-input events as well as changes caused by other
 * mechanisms like keyboard typing.
 *
 * If the client is unaware of the text around the cursor, it should not
 * issue this request, to signify lack of support to the compositor.
 *
 * Text is UTF-8 encoded, and should include the cursor position, the
 * complete selection and additional characters before and after them.
 * There is a maximum length of wayland messages, so text can not be
 * longer than 4000 bytes.
 *
 * Cursor is the byte offset of the cursor within text buffer.
 *
 * Anchor is the byte offset of the selection anchor within text buffer.
 * If there is no selected text, anchor is the same as cursor.
 *
 * If any preedit text is present, it is replaced with a cursor for the
 * purpose of this event.
 *
 * Values set with this request are double-buffered. They will get applied
 * on the next zwp_text_input_v3.commit request, and stay valid until the
 * next committed enable or disable request.
 *
 * The initial state for affected fields is empty, meaning that the text
 * input does not support sending surrounding text. If the empty values
 * get applied, subsequent attempts to change them may have no effect.
 */
static inline void
zwp_text_input_v3_set_surrounding_text(struct zwp_text_input_v3 *zwp_text_input_v3, const char *text, int32_t cursor, int32_t anchor)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_text_input_v3,
			 ZWP_TEXT_INPUT_V3_SET_SURROUNDING_TEXT, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_text_input_v3), 0, text, cursor, anchor);
}

/**
 * @ingroup iface_zwp_text_input_v3
 *
 * Tells the compositor why the text surrounding the cursor changed.
 *
 * Whenever the client detects an external change in text, cursor, or
 * anchor posision, it must issue this request to the compositor. This
 * request is intended to give the input method a chance to update the
 * preedit text in an appropriate way, e.g. by removing it when the user
 * starts typing with a keyboard.
 *
 * cause describes the source of the change.
 *
 * The value set with this request is double-buffered. It must be applied
 * and reset to initial at the next zwp_text_input_v3.commit request.
 *
 * The initial value of cause is input_method.
 */
static inline void
zwp_text_input_v3_set_text_change_cause(struct zwp_text_input_v3 *zwp_text_input_v3, uint32_t cause)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_text_input_v3,
			 ZWP_TEXT_INPUT_V3_SET_TEXT_CHANGE_CAUSE, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_text_input_v3), 0, cause);
}

/**
 * @ingroup iface_zwp_text_input_v3
 *
 * Sets the content purpose and content hint. While the purpose is the
 * basic purpose of an input field, the hint flags allow to modify some of
 * the behavior.
 *
 * Values set with this request are double-buffered. They will get applied
 * on the next zwp_text_input_v3.commit request.
 * Subsequent attempts to update them may have no effect. The values
 * remain valid until the next committed enable or disable request.
 *
 * The initial value for hint is none, and the initial value for purpose
 * is normal.
 */
static inline void
zwp_text_input_v3_set_content_type(struct zwp_text_input_v3 *zwp_text_input_v3, uint32_t hint, uint32_t purpose)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_text_input_v3,
			 ZWP_TEXT_INPUT_V3_SET_CONTENT_TYPE, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_text_input_v3), 0, hint, purpose);
}

/**
 * @ingroup iface_zwp_text_input_v3
 *
 * Marks an area around the cursor as a x, y, width, height rectangle in
 * surface local coordinates.
 *
 * Allows the compositor to put a window with word suggestions near the
 * cursor, without obstructing the text being input.
 *
 * If the client is unaware of the position of edited text, it should not
 * issue this request, to signify lack of support to the compositor.
 *
 * Values set with this request are double-buffered. They will get applied
 * on the next zwp_text_input_v3.commit request, and stay valid until the
 * next committed enable or disable request.
 *
 * The initial values describing a cursor rectangle are empty. That means
 * the text input does not support describing the cursor area. If the
 * empty values get applied, subsequent attempts to change them may have
 * no effect.
 */
static inline void
zwp_text_input_v3_set_cursor_rectangle(struct zwp_text_input_v3 *zwp_text_input_v3, int32_t x, int32_t y, int32_t width, int32_t height)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_text_input_v3,
			 ZWP_TEXT_INPUT_V3_SET_CURSOR_RECTANGLE, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_text_input_v3), 0, x, y, width, height);
}

/**
 * @ingroup iface_zwp_text_input_v3
 *
 * Atomically applies state changes recently sent to the compositor.
 *
 * The commit request establishes and updates the state of the client, and
 * must be issued after any changes to apply them.
 *
 * Text input state (enabled status, content purpose, content hint,
 * surrounding text and change cause, cursor rectangle) is conceptually
 * double-buffered within the context of a text input, i.e. between a
 * committed enable request and the following committed enable or disable
 * request.
 *
 * Protocol requests modify the pending state, as opposed to the current
 * state in use by the input method. A commit request atomically applies
 * all pending state, replacing the current state. After commit, the new
 * pending state is as documented for each related request.
 *
 * Requests are applied in the order of arrival.
 *
 * Neither current nor pending state are modified unless noted otherwise.
 *
 * The compositor must count the number of commit requests coming from
 * each zwp_text_input_v3 object and use the count as the serial in done
 * events.
 */
static inline void
zwp_text_input_v3_commit(struct zwp_text_input_v3 *zwp_text_input_v3)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_text_input_v3,
			 ZWP_TEXT_INPUT_V3_COMMIT, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_text_input_v3), 0);
}

#define ZWP_TEXT_INPUT_MANAGER_V3_DESTROY 0
#define ZWP_TEXT_INPUT_MANAGER_V3_GET_TEXT_INPUT 1


/**
 * @ingroup iface_zwp_text_input_manager_v3
 */
#define ZWP_TEXT_INPUT_MANAGER_V3_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_manager_v3
 */
#define ZWP_TEXT_INPUT_MANAGER_V3_GET_TEXT_INPUT_SINCE_VERSION 1

/** @ingroup iface_zwp_text_input_manager_v3 */
static inline void
zwp_text_input_manager_v3_set_user_data(struct zwp_text_input_manager_v3 *zwp_text_input_manager_v3, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwp_text_input_manager_v3, user_data);
}

/** @ingroup iface_zwp_text_input_manager_v3 */
static inline void *
zwp_text_input_manager_v3_get_user_data(struct zwp_text_input_manager_v3 *zwp_text_input_manager_v3)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwp_text_input_manager_v3);
}

static inline uint32_t
zwp_text_input_manager_v3_get_version(struct zwp_text_input_manager_v3 *zwp_text_input_manager_v3)
{
	return wl_proxy_get_version((struct wl_proxy *) zwp_text_input_manager_v3);
}

/**
 * @ingroup iface_zwp_text_input_manager_v3
 *
 * Destroy the wp_text_input_manager object.
 */
static inline void
zwp_text_input_manager_v3_destroy(struct zwp_text_input_manager_v3 *zwp_text_input_manager_v3)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwp_text_input_manager_v3,
			 ZWP_TEXT_INPUT_MANAGER_V3_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwp_text_input_manager_v3), WL_MARSHAL_FLAG_DESTROY);
}

/**
 * @ingroup iface_zwp_text_input_manager_v3
 *
 * Creates a new text-input object for a given seat.
 */
static inline struct zwp_text_input_v3 *
zwp_text_input_manager_v3_get_text_input(struct zwp_text_input_manager_v3 *zwp_text_input_manager_v3, struct wl_seat *seat)
{
	struct wl_proxy *id;

	id = wl_proxy_marshal_flags((struct wl_proxy *) zwp_text_input_manager_v3,
			 ZWP_TEXT_INPUT_MANAGER_V3_GET_TEXT_INPUT, &zwp_text_input_v3_interface, wl_proxy_get_version((struct wl_proxy *) zwp_text_input_manager_v3), 0, NULL, seat);

	return (struct zwp_text_input_v3 *) id;
}

#ifdef  __cplusplus
}
#endif

#endif
