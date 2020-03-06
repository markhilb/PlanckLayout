#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_norwegian.h"


#undef NO_QUOT
#define NO_QUOT KC_BSLS // '
#undef NO_TILD
#define NO_TILD RALT(KC_RBRC) // ~

// Shift layout defines
#undef NO_SQUOT
#define NO_SQUOT KC_AT // "
#undef NO_SBSLS
#define NO_SBSLS KC_GRAVE // |


enum keyboard_layouts
{
	QGMLW_NO,
	QGMLW_US,
	QWERTY,
	COLEMAK,
	DVORAK,

	NORMAL_LOWER,
	NORMAL_RAISE,

	NUMPAD,

	QGMLW_NO_LOWER,
	QGMLW_US_LOWER,

	QGMLW_NO_RAISE,
	QGMLW_US_RAISE,

	ADJUST
};


#define lower MO(NORMAL_LOWER)
#define raise MO(NORMAL_RAISE)

#define numpad MO(NUMPAD)

#define QNLower MO(QGMLW_NO_LOWER)
#define QELower MO(QGMLW_US_LOWER)

#define QNRaise MO(QGMLW_NO_RAISE)
#define QERaise MO(QGMLW_US_RAISE)

#define adjust MO(ADJUST)

int get_language(void);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qgmlw
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   G  |   M  |   L  |   W  |   B  |   Y  |   U  |   V  |   '" | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   D  |   S  |   T  |   N  |   R  |   I  |   A  |   E  |   O  |  H   | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   F  |   J  |   K  |   P  |  ,;  |  .:  |  -_  |   \| |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | NmPd  | GUI  | Alt | Lower| Space|Space |Raise | Left | Down | Up   | Right|
 * `-----------------------------------------------------------------------------------'
 */
/* Norwegian Layout */
[QGMLW_NO] = LAYOUT_ortho_4x12(
	KC_TAB,  KC_Q,   KC_G,    KC_M,    KC_L,    KC_W,   KC_B,   KC_Y,    KC_U,    KC_V,    KC_BSLS, KC_BSPC,
	KC_ESC,  KC_D,   KC_S,    KC_T,    KC_N,    KC_R,   KC_I,   KC_A,    KC_E,    KC_O,    KC_H,    KC_ENT,
	KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_F,    KC_J, 	 KC_K,   KC_P,    KC_COMM, KC_DOT,  NO_MINS, NO_BSLS,
	KC_LCTL, numpad, KC_LGUI, KC_LALT, QNLower, KC_SPC, KC_SPC, QNRaise, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* English Layout */
[QGMLW_US] = LAYOUT_ortho_4x12(
	KC_TAB,  KC_Q,   KC_G,    KC_M,    KC_L,    KC_W,   KC_B,   KC_Y,    KC_U,    KC_V,    KC_QUOT, KC_BSPC,
	KC_ESC,  KC_D,   KC_S,    KC_T,    KC_N,    KC_R,   KC_I,   KC_A,    KC_E,    KC_O,    KC_H,    KC_ENT,
	KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_F,    KC_J,   KC_K,   KC_P,    KC_COMM, KC_DOT,  KC_MINS, KC_BSLS,
	KC_LCTL, numpad, KC_LGUI, KC_LALT, QELower, KC_SPC, KC_SPC, QERaise, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  /?  | Shft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Nmpd | GUI  | Alt  | Lower| Space|Space |Raise | Left | Down | Up   | Right|
 * `-----------------------------------------------------------------------------------'
 */
[QWERTY] = LAYOUT_ortho_4x12(
	KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    KC_BSPC,
	KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, KC_ENT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT,
	KC_LCTL, KC_LALT, KC_LGUI, numpad, lower, KC_SPC, KC_SPC, raise, KC_LEFT, KC_DOWN,KC_UP,   KC_RIGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | NmPd | Lower| Space|Space |Raise | Left | Down | Up   | Right|
 * `-----------------------------------------------------------------------------------'
 */
[COLEMAK] = LAYOUT_ortho_4x12(
	KC_TAB,  KC_Q,    KC_W,    KC_F,   KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
	KC_ESC,  KC_A,    KC_R,    KC_S,   KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    KC_ENT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT ,
	KC_LCTL, KC_LALT, KC_LGUI, numpad, lower, KC_SPC, KC_SPC, raise, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | NmPd | Lower| Space|Space |Raise | Left | Down | Up   | Right|
 * `-----------------------------------------------------------------------------------'
 */
[DVORAK] = LAYOUT_ortho_4x12(
	KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P,  KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,  KC_BSPC,
	KC_ESC,  KC_A,    KC_O,    KC_E,   KC_U,  KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    KC_S,  KC_ENT,
	KC_LSFT, KC_SCLN, KC_Q,    KC_J,   KC_K,  KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,  KC_SLSH,
	KC_LCTL, KC_LALT, KC_LGUI, numpad, lower, KC_SPC, KC_SPC, raise, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
),

/* Lower (Normal)
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[NORMAL_LOWER] = LAYOUT_ortho_4x12(
	KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
	KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
	_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_END,  _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, adjust,  KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise (Normal)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Dn |Pg Up |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[NORMAL_RAISE] = LAYOUT_ortho_4x12(
	KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
	KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
	_______, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_PGDN, KC_PGUP, _______, _______, _______,
	_______, _______, _______, _______, adjust, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |  TAB |      |      |      |      |      |      |   7  |   8  |   9  |   /  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ESC |      |      |      |      |      |      |   4  |   5  |   6  |   *  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |   ,  |   .  |   +  |      |
 * `-----------------------------------------------------------------------------------'
 */
[NUMPAD] = LAYOUT_ortho_4x12(
	KC_TAB,  _______, _______, _______, _______, _______, _______, KC_7, KC_8,    KC_9,   KC_KP_SLASH,    _______,
	KC_ESC,  _______, _______, _______, _______, _______, _______, KC_4, KC_5,    KC_6,   KC_KP_ASTERISK, _______,
	_______, _______, _______, _______, _______, _______, _______, KC_1, KC_2,    KC_3,   KC_KP_MINUS,    _______,
	_______, _______, _______, _______, _______, _______, _______, KC_0, KC_COMM, KC_DOT, KC_KP_PLUS,     _______
),

/* Lower - QGMLW
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   [  |   {  |   (  |   =  |   +  |   *  |   /  |   )  |   }  |   ]  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Del | Mute |      |BrwRef|      |      |      |   <  |   >  |   %  |   &  |   ~  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |Sleep |ScrLck| caps |NumLck|PrtScr|  Ins | Home | End  |   æ  |   ø  |  å   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctrl  |  Alt |      |      |      |             |Adjust| Next | BriD | BriU | Play |
 * `-----------------------------------------------------------------------------------'
 */
/* Norwegian */

[QGMLW_NO_LOWER] = LAYOUT_ortho_4x12(
	KC_EXLM, NO_LBRC, NO_LCBR, NO_LPRN, NO_EQL,  NO_PLUS, NO_ASTR, NO_SLSH, NO_RPRN, NO_RCBR, NO_RBRC, KC_BSPC,
	KC_DEL,  KC_MUTE, _______, KC_WREF, _______, _______, _______, NO_LESS, NO_GRTR, KC_PERC, NO_AMPR, NO_TILD,
	KC_LSFT, KC_SLEP, KC_SLCK, KC_CAPS, KC_NLCK, KC_PSCR, KC_INS,  KC_HOME, KC_END,  NO_AE,   NO_OSLH, NO_AA,
	KC_LCTL, KC_LALT, _______, _______, adjust,  _______, _______, adjust,  KC_MNXT, KC_BRID, KC_BRIU, KC_MPLY
),
/* English Same as Nok - without æøå */
[QGMLW_US_LOWER] = LAYOUT_ortho_4x12(
	KC_EXLM, KC_LBRC, KC_LCBR, KC_LPRN, KC_EQL,  KC_PLUS, KC_ASTR, KC_SLSH, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSPC,
	KC_DEL,  KC_MUTE, _______, KC_WREF, _______, _______, _______, KC_LT,  KC_GT,    KC_PERC, KC_AMPR, KC_TILD,
	KC_LSFT, KC_SLEP, KC_SLCK, KC_CAPS, KC_NLCK, KC_PSCR, KC_INS,  KC_HOME, KC_END,  _______, _______, _______,
	KC_LCTL, KC_LALT, _______, _______, adjust,  _______, _______, adjust,  KC_MNXT, KC_BRID, KC_BRIU, KC_MPLY
),

/* Raise - QGMLW
 * ,-----------------------------------------------------------------------------------.
 * |   ?  |   9  |   7  |   5  |   3  |   1  |   0  |  2   |   4  |   6  |   8  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Del |  F1  |  F2  |  F3  |   F4 |   F5 |  F6  |   #  |   @  |   ^  |   $  |   `  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift|  F7  |  F8  | F9   |  F10 |  F11 |  F12 | PgDn | PgUp |   Æ  |   Ø  |  Å   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RCtrl |  RAlt|      |      |      |             |Adjust| Next | VolDn| VolUp| Play |
 * `-----------------------------------------------------------------------------------'
 */
/* Norwegian */
[QGMLW_NO_RAISE] = LAYOUT_ortho_4x12(
	NO_QUES,      KC_9,    KC_7,    KC_5,    KC_3,   KC_1,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    KC_BSPC,
	LCTL(KC_DEL), KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_HASH, NO_AT,   NO_CIRC, NO_DLR,  NO_GRV,
	KC_RSFT,      KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_PGDN, KC_PGUP, KC_DQUO, KC_COLN, KC_LCBR,
	KC_RCTL,      KC_RALT, _______, _______, adjust, _______, _______, adjust,  KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),
/* English */
[QGMLW_US_RAISE] = LAYOUT_ortho_4x12(
	KC_QUES,      KC_9,    KC_7,    KC_5,    KC_3,   KC_1,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    KC_BSPC,
	LCTL(KC_DEL), KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_HASH, KC_AT,   KC_CIRC, KC_DLR,  KC_GRV,
	KC_RSFT,      KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_PGDN, KC_PGUP, _______, _______, _______,
	KC_RCTL,      KC_RALT, _______, _______, adjust, _______, _______, adjust,  KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust, every thing on top row (except backspace) is related to rgb stuff
 * ,-----------------------------------------------------------------------------------.
 * |      |Reset |Debug |RGBTGL|RGBMDE| Hue+ | Hue- | Sat+ | Sat- | BriU | BriD | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MseCly| AudOn|AudOff|AgNorm|AgSwap|Dvorak|Colmak|Qwerty|QgmlwE|QgmlwN|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice+|Voice-|MusOn |MusOff|MIDIOn|MIDIOF|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[ADJUST] = LAYOUT_ortho_4x12(
	_______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI,    RGB_SAD,     RGB_VAI,    RGB_VAD,      KC_DEL,
	_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(DVORAK), DF(COLEMAK), DF(QWERTY), DF(QGMLW_US), DF(QGMLW_NO),
	_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON,    TERM_OFF,    _______,    _______,      _______,
	_______, _______, _______, _______, _______, _______, _______, _______,    _______,     _______,    _______,      _______
)

};

/*
	Macros
*/

// Keycode conversion struct
typedef struct shift_code {
	uint16_t pre;
	uint16_t post;
	int lang;
} shift_code_t;


// Keycodes to be changed in shift layout
const shift_code_t SHIFT_CODES[] = {
	// NO
	{.lang = QGMLW_NO, .pre = NO_QUOT, .post = NO_SQUOT},
	{.lang = QGMLW_NO, .pre = NO_BSLS, .post = NO_SBSLS},
	// US
	{.lang = QGMLW_US, .pre = KC_COMM, .post = KC_SCLN},
	{.lang = QGMLW_US, .pre = KC_DOT,  .post = KC_COLN},
};

const uint16_t SHIFT_CODES_SIZE = sizeof(SHIFT_CODES) / sizeof(SHIFT_CODES[0]);


bool handle_special_characters(uint16_t keycode, keyrecord_t *record)
{
	if (get_mods() & MOD_MASK_SHIFT)
    {
		int current_language = get_language();

		// No action was needed
		if (current_language == -1)
			return true;

		for (int i = 0; i < SHIFT_CODES_SIZE; i++)
        {
			// Shifted key is changed
			if (current_language == SHIFT_CODES[i].lang && keycode == SHIFT_CODES[i].pre)
            {
				// Shift disabled
				unregister_code(KC_LSFT);

				// Tap the desired key
				tap_code16(SHIFT_CODES[i].post);
				register_code(KC_LSFT);
				return false;
			}
		}
	}

    return true;
}


// Macros for when keycode is registered
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (record->event.pressed)
    {
	    if(!handle_special_characters(keycode, record))
            return false;
	}

	return true;
}


inline int get_language()
{
    if(layer_state_cmp(default_layer_state, QGMLW_NO))
        return QGMLW_NO;

    if(layer_state_cmp(default_layer_state, QGMLW_US))
        return QGMLW_US;

    // No relevant action needed
    return -1;
}

