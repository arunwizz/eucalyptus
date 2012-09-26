/*************************************************************************
 * Copyright 2009-2012 Eucalyptus Systems, Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 * Please contact Eucalyptus Systems, Inc., 6755 Hollister Ave., Goleta
 * CA 93117, USA or visit http://www.eucalyptus.com/licenses/ if you need
 * additional information or have any questions.
 ************************************************************************/
package com.eucalyptus.reporting.art.generator;

import javax.persistence.EntityTransaction;
import org.hibernate.CacheMode;
import org.hibernate.ScrollMode;
import org.hibernate.ScrollableResults;
import org.hibernate.criterion.Criterion;
import org.hibernate.criterion.Order;
import com.eucalyptus.entities.Entities;
import com.eucalyptus.reporting.domain.ReportingAccount;
import com.eucalyptus.reporting.domain.ReportingAccountDao;
import com.eucalyptus.reporting.domain.ReportingUser;
import com.eucalyptus.reporting.domain.ReportingUserDao;
import com.google.common.base.Predicate;

/**
 *
 */
public abstract class AbstractArtGenerator implements ArtGenerator {

  protected static final String TIMESTAMP_MS = "timestampMs";

	protected ReportingUser getUserById( final String userId ) {
    return ReportingUserDao.getInstance().getReportingUser( userId );
  }

  protected ReportingAccount getAccountById( final String accountId ) {
    return ReportingAccountDao.getInstance().getReportingAccount( accountId );
  }

  @SuppressWarnings( "unchecked" )
  protected <ET> void foreach( final Class<ET> eventClass,
                               final Criterion criterion,
                               final boolean ascending,
                               final Predicate<? super ET> callback ) {
    final EntityTransaction transaction = Entities.get( eventClass );
    ScrollableResults results = null;
    try {
      results = Entities.createCriteria( eventClass )
          .setReadOnly( true )
          .setCacheable( false )
          .setCacheMode( CacheMode.IGNORE )
          .setFetchSize( 100 )
          .add( criterion )
          .addOrder( ascending ? Order.asc( TIMESTAMP_MS ) : Order.desc( TIMESTAMP_MS ) )
          .scroll( ScrollMode.FORWARD_ONLY );

      while ( results.next() ) {
        final ET event = (ET) results.get( 0 );
        if ( !callback.apply( event ) ) {
          break;
        }
        Entities.evict( event );
      }
    } finally {
      if (results != null) try { results.close(); } catch( Exception e ) { }
      transaction.rollback();
    }
  }

}
