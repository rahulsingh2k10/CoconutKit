//
//  HLSExpandingSearchBar.h
//  CoconutKit
//
//  Created by Samuel Défago on 11.06.12.
//  Copyright (c) 2012 Hortis. All rights reserved.
//

#import "HLSAnimation.h"

// Search button alignment
typedef enum {
    HLSExpandingSearchBarAlignmentLeft = 0,
    HLSExpandingSearchBarAlignmentRight,
} HLSExpandingSearchBarAlignment;

// Forward declarations
@protocol HLSExpandingSearchBarDelegate;

/**
 * A search bar which collapses to a button and can be expanded when needed. Completely similar to a UISearchBar.
 *
 * The search bar frame corresponds to the area where the search bar stretches when it expands. You can control
 * whether the search bar collapses to a button on the left or on the right using the alignment property.
 */
@interface HLSExpandingSearchBar : UIView <HLSAnimationDelegate, UISearchBarDelegate> {
@private
    UISearchBar *m_searchBar;
    UIButton *m_searchButton;
    HLSExpandingSearchBarAlignment m_alignment;
    id<HLSExpandingSearchBarDelegate> m_delegate;
    HLSAnimation *m_animation;
    BOOL m_layoutDone;
    BOOL m_expanded;
    BOOL m_animating;
}

/**
 * These properties are exactly the same as for UISearchBar. Refer to their documentation for more information
 */
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *prompt;
@property (nonatomic, copy) NSString *placeholder;
@property (nonatomic, assign) BOOL showsBookmarkButton;
@property (nonatomic, assign) BOOL showsCancelButton;
@property (nonatomic, assign) BOOL showsSearchResultsButton;

@property (nonatomic, assign) UITextAutocapitalizationType autocapitalizationType;
@property (nonatomic, assign) UITextAutocorrectionType autocorrectionType;
@property (nonatomic, assign) UITextSpellCheckingType spellCheckingType;
@property (nonatomic, assign) UIKeyboardType keyboardType;

/**
 * Set whether the search button is left-aligned (expansion to the right) or right-aligned (expansion to the left).
 * Default value is HLSExpandingSearchBarAlignmentLeft
 */
@property (nonatomic, assign) HLSExpandingSearchBarAlignment alignment;

/**
 * The search bar delegate
 */
@property (nonatomic, assign) id<HLSExpandingSearchBarDelegate> delegate;

/**
 * Expand or collapse the search bar
 */
- (void)setExpanded:(BOOL)expanded animated:(BOOL)animated;

@end

@protocol HLSExpandingSearchBarDelegate <NSObject>

// Called when the search bar expands or collapses
- (BOOL)expandingSearchBarDidExpand:(HLSExpandingSearchBar *)searchBar animated:(BOOL)animated;
- (BOOL)expandingSearchBarDidCollapse:(HLSExpandingSearchBar *)searchBar animated:(BOOL)animated;

// Refer to the documentation of the same methods declared by UISearchBarDelegate
- (BOOL)expandingSearchBarShouldBeginEditing:(HLSExpandingSearchBar *)searchBar;
- (void)expandingSearchBarTextDidBeginEditing:(HLSExpandingSearchBar *)searchBar;
- (BOOL)expandingSearchBarShouldEndEditing:(HLSExpandingSearchBar *)searchBar;
- (void)expandingSearchBarTextDidEndEditing:(HLSExpandingSearchBar *)searchBar;
- (void)expandingSearchBar:(HLSExpandingSearchBar *)searchBar textDidChange:(NSString *)searchText;
- (BOOL)expandingSearchBar:(HLSExpandingSearchBar *)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

- (void)expandingSearchBarSearchButtonClicked:(HLSExpandingSearchBar *)searchBar;
- (void)expandingSearchBarBookmarkButtonClicked:(HLSExpandingSearchBar *)searchBar;
- (void)expandingSearchBarCancelButtonClicked:(HLSExpandingSearchBar *) searchBar;
- (void)expandingSearchBarResultsListButtonClicked:(HLSExpandingSearchBar *)searchBar;

@end
